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
    QFile f("genericinit.rec");
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
        m_queries[el.attribute("name")] = QSqlQuery(req, m_db);
    }

    qDebug()<<"Req"<<m_queries.keys();

    return true;
}

QMap<QUuid, CreaturePointer> SqlDataBase::selectCreature(QList<QUuid>)
{
    return QMap<QUuid, CreaturePointer>();
}

bool SqlDataBase::removeCreature(CreaturePointer)
{
    return false;
}

bool SqlDataBase::updateCreature(CreaturePointer)
{
    return false;
}

bool SqlDataBase::addCreature(CreaturePointer)
{
    return false;
}
