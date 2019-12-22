#include "controllermainmaster.h"

ControllerMainMaster::ControllerMainMaster(): QObject(nullptr)
{

}

ControllerMainMaster::~ControllerMainMaster()
{

}

void ControllerMainMaster::exec()
{
    qDebug()<<roller.roll(100,10,1).first();
}
