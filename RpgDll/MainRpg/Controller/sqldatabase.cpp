#include "sqldatabase.h"

SqlDataBase::SqlDataBase(QObject *parent) : QObject(parent)
{
    m_db.setDatabaseName("generic_database");
    m_db.open();
}

SqlDataBase::~SqlDataBase()
{
    m_db.close();
}

QList<CreaturePointer> SqlDataBase::selectCreature(QList<QUuid>) const
{
    return QList<CreaturePointer>();
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
