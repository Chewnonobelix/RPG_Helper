#include "abstractpc.h"

AbstractPc::AbstractPc(const AbstractPc& pc) : QObject(), MetaData(pc)
{}

int AbstractPc::level() const
{
    return 0;
}

void AbstractPc::setLevel(int)
{

}

double AbstractPc::currentXp() const
{
    return 0;
}

void AbstractPc::setCurrentXp(double)
{

}

double AbstractPc::targetXp() const
{
    return 0;
}

void AbstractPc::setTargetXp(double)
{

}

QStringList AbstractPc::classes() const
{
    return QStringList();
}

void AbstractPc::setClasses(QStringList)
{

}

bool AbstractPc::operator ==(const AbstractPc&) const
{
    return false;
}

bool AbstractPc::operator < (const AbstractPc&) const
{
    return false;
}

AbstractPc& AbstractPc::operator = (const AbstractPc&)
{
    return *this;
}

