#include "sqldatabase.h"

SqlDataBase::SqlDataBase() : InterfaceDataSave()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE", "default");
    m_db.setDatabaseName("generic");
    qDebug()<<"Open"<<m_db.open();
}

SqlDataBase::~SqlDataBase()
{
    m_db.close();
}

bool SqlDataBase::init()
{
    QString filename = QFile::exists("genericinit.rec") ? "genericinit.rec" : REQFILE;
    QFile f(filename);
    bool ret = f.open(QIODevice::ReadOnly);
    if(!ret)
        throw QString("Cannot find " + f.fileName());

    QDomDocument doc;
    ret = doc.setContent(&f);
    f.close();

    if(!ret)
        throw QString("Cannot set content");

    auto root = doc.documentElement();

    for(auto it: {"init", "trigger"})
    {
        auto in = root.elementsByTagName(it);

        for(int i = 0; i < in.size(); i++)
        {
            QDomElement el = in.at(i).toElement();
            QString req = el.text();
            auto res = m_db.exec(req);
            qDebug()<<res.executedQuery()<<res.lastError();
        }
    }

    auto in = root.elementsByTagName("request");

    for(int i = 0; i < in.size(); i++)
    {
        QDomElement el = in.at(i).toElement();
        QString req = el.text();
        m_queries[el.attribute("name")] = QSqlQuery(m_db);
        m_queries[el.attribute("name")].prepare(req);
    }

    qDebug()<<"Req"<<m_queries.keys()<<m_db.isOpen();

    return true;
}

QMap<QUuid, CreaturePointer> SqlDataBase::selectCreature(QList<QUuid> ids)
{
    auto& carac = m_queries["selectCreatureCarac"];
    auto& assoc = m_queries["selectCreatureAssoc"];
    auto& creat = m_queries["selectCreature"];

    creat.exec();

    while (creat.next())
    {
        if(m_creatures.contains(creat.value("id").toUuid()))
            continue;

        CreaturePointer c = AbstractCreature::createGeneric();
        c->setId(creat.value("id").toUuid());
        c->setName(creat.value("name").toString());
        c->setRace(creat.value("race").toString());
        c->setDescription(creat.value("description").toString());

        m_creatures[c->id()] = c;

        carac.bindValue(":id", c->id());

        carac.exec();
        while(carac.next())
            c->setCharacteristics(carac.value("name").toString(), carac.value("value").toDouble());

        assoc.bindValue(":id", c->id());
        assoc.exec();

        while(assoc.next())
        {
            if(!assoc.value("item").toString().isEmpty())
            {
                auto i = selectItem({assoc.value("item").toUuid()}).first();
                c->setItem(assoc.value("typeName").toString(), i);
            }
            if(!assoc.value("rule").toString().isEmpty())
            {
                auto i = selectRule({assoc.value("rule").toUuid()}).first();
                c->setRule(assoc.value("typeName").toString(), i);
            }
            if(!assoc.value("weapon").toString().isEmpty())
            {
                auto i = selectWeapon({assoc.value("weapon").toUuid()}).first();
                c->setWeapon(i);
            }
        }
    }

    QMap<QUuid, CreaturePointer> ret;
    for(auto it: ids)
        ret[it] = m_creatures[it];

    return ids.isEmpty() ? m_creatures : ret;

    return ret;
}

bool SqlDataBase::removeCreature(CreaturePointer c)
{
    auto& req = m_queries["removeCreature"];
    req.bindValue(":id", c->id());
    bool ret = req.exec();
    m_creatures.remove(c->id());

    return ret;
}

bool SqlDataBase::updateCreature(CreaturePointer c)
{
    auto& req = m_queries["updateCreature"];
    req.bindValue(":name", c->name());
    req.bindValue(":race", c->race());
    req.bindValue(":description", c->description());
    req.bindValue(":id", c->id());

    bool ret = req.exec();

    ret &= insertCaracteristic(c);

    ret &= insertAssociation(c);

    return ret;
}

bool SqlDataBase::addCreature(CreaturePointer c)
{
    if(c->id().isNull())
        c->setId(QUuid::createUuid());
    m_creatures[c->id()] = c;

    auto& insertCreat = m_queries["insertCreature"];

    insertCreat.bindValue(":id", c->id());
    insertCreat.bindValue(":race", c->race());
    insertCreat.bindValue(":description", c->description());
    insertCreat.bindValue(":name", c->name());

    if(!insertCreat.exec())
    {
        qDebug()<<"Insert creat"<<insertCreat.lastError()<<insertCreat.lastQuery()<<insertCreat.boundValues();
        return false;
    }

    if(!insertCaracteristic(c))
        return false;

    if(!insertAssociation(c))
        return false;

    return true;
}

bool SqlDataBase::insertAssociation(CreaturePointer c)
{
    auto& insertAssoc = m_queries["insertCreatureAssociation"];
    bool ret = true;

    for(auto it: c->ruleTypeList())
    {
        for(auto it2: c->ruleSet(it))
        {
            insertAssoc.bindValue(":id", c->id());
            insertAssoc.bindValue(":typeName", it);
            insertAssoc.bindValue(":rule", it2->id());
            insertAssoc.bindValue(":item", QVariant());
            insertAssoc.bindValue(":weapon", QVariant());

            ret &= insertAssoc.exec();
        }
    }
    for(auto it: c->itemTypeList())
    {
        if(it == "weapon")
            continue;

        for(auto it2: c->itemSet(it))
        {
            insertAssoc.bindValue(":id", c->id());
            insertAssoc.bindValue(":typeName", it);
            insertAssoc.bindValue(":rule", QVariant());
            insertAssoc.bindValue(":item", it2->id());
            insertAssoc.bindValue(":weapon", QVariant());
            ret &= insertAssoc.exec();
        }
    }

    for(auto it: c->weapons())
    {
        insertAssoc.bindValue(":id", c->id());
        insertAssoc.bindValue(":rule", QVariant());
        insertAssoc.bindValue(":item", QVariant());
        insertAssoc.bindValue(":weapon", it->id());
        ret &= insertAssoc.exec();
    }

    return ret;
}

bool SqlDataBase::insertCaracteristic(CreaturePointer c)
{
    bool ret = true;
    auto& insertCarac = m_queries["insertCreatureCarac"];

    for(auto it: c->characteristicsList())
    {
        insertCarac.bindValue(":id", c->id());
        insertCarac.bindValue(":name", it);
        insertCarac.bindValue(":value", c->characteristics(it));

        if(!(ret = insertCarac.exec()))
            qDebug()<<"Insert carac"<<insertCarac.boundValues()<<insertCarac.lastError();

    }

    return ret;
}

QMap<QUuid, RulePointer> SqlDataBase::selectRule(QList<QUuid> ids)
{
    auto& req = m_queries["selectRule"];

    req.exec();

    while(req.next())
    {
        if(m_rules.contains(req.value("id").toUuid()))
            continue;

        RulePointer r = AbstractRule::createGeneric();
        r->setId(req.value("id").toUuid());
        r->setName(req.value("name").toString());
        r->setDescription(req.value("description").toString());

        m_rules[r->id()] = r;
    }
    QMap<QUuid, RulePointer> ret;
    for(auto it: ids)
        ret[it] = m_rules[it];

    return ids.isEmpty() ? m_rules : ret;
}

bool SqlDataBase::removeRule(RulePointer r)
{
    auto& req = m_queries["removeRule"];

    req.bindValue(":id", r->id());
    m_rules.remove(r->id());
    return req.exec();
}

bool SqlDataBase::updateRule(RulePointer r)
{
    auto& req = m_queries["updateRule"];

    req.bindValue(":id", r->id());
    req.bindValue(":name", r->name());
    req.bindValue(":description", r->description());
    return req.exec();
}

bool SqlDataBase::addRule(RulePointer r)
{
    if(r->id().isNull())
        r->setId(QUuid::createUuid());

    m_rules[r->id()] = r;
    auto& req = m_queries["insertRule"];
    req.bindValue(":id", r->id());
    req.bindValue(":name", r->name());
    req.bindValue(":description", r->description());

    return req.exec();
}

QMap<QUuid, ObjectPointer> SqlDataBase::selectItem(QList<QUuid> ids)
{
    auto& req = m_queries["selectObject"];

    req.exec();

    while(req.next())
    {
        if(m_item.contains(req.value("id").toUuid()))
            continue;

        ObjectPointer r = AbstractObject::createGeneric();
        r->setId(req.value("id").toUuid());
        r->setName(req.value("name").toString());

        m_item[r->id()] = r;
    }

    QMap<QUuid, ObjectPointer> ret;
    for(auto it: ids)
        ret[it] = m_item[it];

    return ids.isEmpty() ? m_item : ret;
}

bool SqlDataBase::removeItem(ObjectPointer o)
{
    auto& req = m_queries["removeObject"];

    req.bindValue(":id", o->id());
    m_item.remove(o->id());
    return req.exec();
}

bool SqlDataBase::updateItem(ObjectPointer o)
{
    auto& req = m_queries["updateObject"];

    req.bindValue(":id", o->id());
    req.bindValue(":name", o->name());
    return req.exec();
}

bool SqlDataBase::addItem(ObjectPointer o)
{
    if(o->id().isNull())
        o->setId(QUuid::createUuid());
    m_item[o->id()] = o;

    auto& req = m_queries["insertObject"];
    req.bindValue(":id", o->id());
    req.bindValue(":name", o->name());

    return req.exec();
}

QMap<QUuid, WeaponPointer> SqlDataBase::selectWeapon(QList<QUuid> ids)
{
    auto items = selectItem(ids);
    auto req = m_queries["selectWeapon"];
    req.exec();
    while(req.next())
    {
        if(m_weapon.contains(req.value("id").toUuid()))
            continue;

        WeaponPointer w = AbstractWeapon::createGeneric();
        w->setDamage(req.value("damage").toString());
        w->setId(req.value("id").toUuid());
        w->setName(items[w->id()]->name());

        m_weapon[w->id()] = w;
    }

    QMap<QUuid, WeaponPointer> ret;
    for(auto it: ids)
        ret[it] = m_weapon[it];

    return ids.isEmpty() ? m_weapon : ret;
}

bool SqlDataBase::removeWeapon(WeaponPointer w)
{
    m_weapon.remove(w->id());

    return removeItem(w);
}

bool SqlDataBase::updateWeapon(WeaponPointer w)
{
    bool ret = updateItem(w);
    if(!ret)
        return ret;

    auto& req = m_queries["updateWeapon"];

    req.bindValue(":id", w->id());
    req.bindValue(":damage", w->damage());
    return req.exec();
}

bool SqlDataBase::addWeapon(WeaponPointer w)
{
    bool ret = addItem(w);
    m_weapon[w->id()] = w;

    if(!ret)
        return ret;

    auto& req = m_queries["insertWeapon"];
    req.bindValue(":id", w->id());
    req.bindValue(":damage", w->damage());

    return req.exec();
}

