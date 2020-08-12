#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

#include <QtSql/QSqlDatabase>
#include "interfacedatasave.h"

class SqlDataBase : public InterfaceDataSave
{
    Q_OBJECT
private:
    QSqlDatabase m_db;

public:
    explicit SqlDataBase(QObject *parent = nullptr);
    ~SqlDataBase();

    QList<CreaturePointer> selectCreature(QList<QUuid>) const;
    bool removeCreature(CreaturePointer);
    bool updateCreature(CreaturePointer);
    bool addCreature(CreaturePointer);

signals:

};

#endif // SQLDATABASE_H
