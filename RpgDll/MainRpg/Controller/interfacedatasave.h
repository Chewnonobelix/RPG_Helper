#ifndef INTERFACEDATASAVE_H
#define INTERFACEDATASAVE_H

#include <QObject>

#include "abstractcreature.h"

class InterfaceDataSave: public QObject
{
public:
    InterfaceDataSave() = default;
    InterfaceDataSave(const InterfaceDataSave&) = delete;
    ~InterfaceDataSave() = default;

    virtual QMap<QUuid, CreaturePointer> selectCreature(QList<QUuid> = QList<QUuid>()) = 0;
    virtual bool removeCreature(CreaturePointer) = 0;
    virtual bool updateCreature(CreaturePointer) = 0;
    virtual bool addCreature(CreaturePointer) = 0;

    virtual QMap<QUuid, RulePointer> selectRule(QList<QUuid> = QList<QUuid>()) = 0;
    virtual bool removeRule(RulePointer) = 0;
    virtual bool updateRule(RulePointer) = 0;
    virtual bool addRule(RulePointer) = 0;

    virtual QMap<QUuid, ObjectPointer> selectItem(QList<QUuid> = QList<QUuid>()) = 0;
    virtual bool removeItem(ObjectPointer) = 0;
    virtual bool updateItem(ObjectPointer) = 0;
    virtual bool addItem(ObjectPointer) = 0;

    virtual bool init() = 0;
};
#endif // INTERFACEDATASAVE_H
