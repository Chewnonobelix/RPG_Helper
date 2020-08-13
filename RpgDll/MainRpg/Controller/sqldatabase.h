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

    QMap<QUuid, CreaturePointer> selectCreature(QList<QUuid> = QList<QUuid>()) override;
    bool removeCreature(CreaturePointer) override;
    bool updateCreature(CreaturePointer) override;
    bool addCreature(CreaturePointer) override;

    QMap<QUuid, RulePointer> selectRule(QList<QUuid> = QList<QUuid>()) override;
    bool removeRule(RulePointer) override;
    bool updateRule(RulePointer) override;
    bool addRule(RulePointer) override;

    QMap<QUuid, ObjectPointer> selectItem(QList<QUuid> = QList<QUuid>()) override;
    bool removeItem(ObjectPointer) override;
    bool updateItem(ObjectPointer) override;
    bool addItem(ObjectPointer) override;

    QMap<QUuid, WeaponPointer> selectWeapon(QList<QUuid> = QList<QUuid>()) override;
    bool removeWeapon(WeaponPointer) override;
    bool updateWeapon(WeaponPointer) override;
    bool addWeapon(WeaponPointer) override;

signals:

};

#endif // SQLDATABASE_H
