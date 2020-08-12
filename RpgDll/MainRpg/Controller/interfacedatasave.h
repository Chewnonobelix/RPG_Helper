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

    virtual bool init() = 0;
};
#endif // INTERFACEDATASAVE_H
