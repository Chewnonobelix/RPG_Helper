#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QMap>
#include "interfacedatasave.h"
#include "../MainRpg_global.h"

class MAINRPG_EXPORT SqlDataBase : public InterfaceDataSave
{
    Q_OBJECT
private:
    QSqlDatabase m_db;
    QMap<QString, QSqlQuery> m_queries;

public:
    SqlDataBase();
    ~SqlDataBase();

    bool init();

    QMap<QUuid, CreaturePointer> selectCreature(QList<QUuid> = QList<QUuid>());
    bool removeCreature(CreaturePointer);
    bool updateCreature(CreaturePointer);
    bool addCreature(CreaturePointer);

signals:

};

#endif // SQLDATABASE_H
