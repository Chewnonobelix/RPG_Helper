#ifndef CONTROLLERMAINMASTER_H
#define CONTROLLERMAINMASTER_H

#include <QObject>
#include <QSharedDataPointer>
#include <QDebug>
#include "../../RpgDll_global.h"

#include "dice.h"

class RPGDLL_EXPORT ControllerMainMaster: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ControllerMainMaster)

public:
    ControllerMainMaster();
    ~ControllerMainMaster();

    void exec();

private:
    Dice roller;

};

#endif // CONTROLLERMAINMASTER_H
