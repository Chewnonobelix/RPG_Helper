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
    QMap<QUuid, CreaturePointer> ret;

    while (creat.next())
    {
        if(!ids.isEmpty() && !ids.contains(creat.value("id").toUuid()))
            continue;

        CreaturePointer c = AbstractCreature::createGeneric();
        c->setId(creat.value("id").toUuid());
        c->setName(creat.value("name").toString());
        c->setRace(creat.value("race").toString());
        c->setDescription(creat.value("description").toString());

        ret[c->id()] = c;

        carac.bindValue(":id", c->id());

        while(carac.next())
            c->setCharacteristics(carac.value("name").toString(), carac.value("value").toDouble());

        assoc.bindValue(":id", c->id());

        while(assoc.next())
        {
            if(!assoc.value("item").isNull())
                qDebug()<<"Load item";
            if(!assoc.value("rule").isNull())
                qDebug()<<"Load rule";
            if(!assoc.value("item").isNull())
                qDebug()<<"Load weapon";
        }
    }

    return ret;
}

bool SqlDataBase::removeCreature(CreaturePointer c)
{
    auto& req = m_queries["removeCreature"];
    req.bindValue(":id", c->id());
    bool ret = req.exec();
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
    return ret;
}

bool SqlDataBase::addCreature(CreaturePointer c)
{
    if(c->id().isNull())
        c->setId(QUuid::createUuid());

    auto& insertCreat = m_queries["insertCreature"];
    auto& insertCarac = m_queries["insertCreatureCarac"];
    auto& insertAssoc = m_queries["insertCreatureAssociation"];

    insertCreat.bindValue(":id", c->id());
    insertCreat.bindValue(":race", c->race());
    insertCreat.bindValue(":description", c->description());
    insertCreat.bindValue(":name", c->name());

    if(!insertCreat.exec())
    {
        qDebug()<<"Insert creat"<<insertCreat.lastError()<<insertCreat.lastQuery()<<insertCreat.boundValues();
        return false;
    }

    for(auto it: c->characteristicsList())
    {
        insertCarac.bindValue(":id", c->id());
        insertCarac.bindValue(":name", it);
        insertCarac.bindValue(":value", c->characteristics(it));

        if(!insertCarac.exec())
            qDebug()<<"Insert carac"<<insertCarac.boundValues()<<insertCarac.lastError();

    }

    return true;
}

QMap<QUuid, RulePointer> SqlDataBase::selectRule(QList<QUuid> ids)
{
    auto& req = m_queries["selectRule"];

    req.exec();
    QMap<QUuid, RulePointer> ret;
    while(req.next())
    {
        if(!ids.isEmpty() && !ids.contains(req.value("id").toUuid()))
            continue;

        RulePointer r = AbstractRule::createGeneric();
        r->setId(req.value("id").toUuid());
        r->setName(req.value("name").toString());
        r->setDescription(req.value("description").toString());

        ret[r->id()] = r;
    }
    return ret;
}

bool SqlDataBase::removeRule(RulePointer r)
{
    auto& req = m_queries["removeRule"];

    req.bindValue(":id", r->id());

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
    QMap<QUuid, ObjectPointer> ret;
    while(req.next())
    {
        if(!ids.isEmpty() && !ids.contains(req.value("id").toUuid()))
            continue;

        ObjectPointer r = AbstractObject::createGeneric();
        r->setId(req.value("id").toUuid());
        r->setName(req.value("name").toString());

        ret[r->id()] = r;
    }
    return ret;
}

bool SqlDataBase::removeItem(ObjectPointer o)
{
    auto& req = m_queries["removeObject"];

    req.bindValue(":id", o->id());

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

    auto& req = m_queries["insertObject"];
    req.bindValue(":id", o->id());
    req.bindValue(":name", o->name());

    return req.exec();
}

QMap<QUuid, WeaponPointer> SqlDataBase::selectWeapon(QList<QUuid> ids)
{
    QMap<QUuid, WeaponPointer> ret;
    auto items = selectItem(ids);
    auto req = m_queries["selectWeapon"];
    req.exec();
    while(req.next())
    {
        if(!ids.isEmpty() && !ids.contains(req.value("id").toUuid()))
            continue;

        WeaponPointer w = AbstractWeapon::createGeneric();
        w->setDamage(req.value("damage").toString());
        w->setId(req.value("id").toUuid());
        w->setName(items[w->id()]->name());

        ret[w->id()] = w;
    }

    return ret;
}

bool SqlDataBase::removeWeapon(WeaponPointer w)
{
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

    if(!ret)
        return ret;

    auto& req = m_queries["insertWeapon"];
    req.bindValue(":id", w->id());
    req.bindValue(":damage", w->damage());

    return req.exec();
}

