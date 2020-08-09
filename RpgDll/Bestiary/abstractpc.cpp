#include "abstractpc.h"

AbstractPc::AbstractPc(const AbstractPc& pc) : QObject(), MetaData(pc)
{}

int AbstractPc::level() const
{
    return metaData<int>("level");
}

void AbstractPc::setLevel(int l)
{
    setMetadata("level", l);
    emit s_level(l);
}

double AbstractPc::currentXp() const
{
    return metaData<double>("currentXp");
}

void AbstractPc::setCurrentXp(double c)
{
    setMetadata("currentXp", c);
    emit s_currentXp(c);
}

double AbstractPc::targetXp() const
{
    return metaData<double>("targetXp");
}

void AbstractPc::setTargetXp(double t)
{
    setMetadata("targetXp", t);
    emit s_targetXp(t);
}

QStringList AbstractPc::classes() const
{
    return metaData<QStringList>("classes");
}

void AbstractPc::setClasses(QStringList c)
{
    setMetadata("classes", c);
    emit s_classes(c);
}

bool AbstractPc::operator ==(const AbstractPc& pc) const
{
    return classes() == pc.classes() &&
        level() == pc.level() &&
        targetXp() == pc.targetXp() &&
        currentXp() == pc.currentXp();
}

bool AbstractPc::operator < (const AbstractPc& pc) const
{
    return classes() == pc.classes() &&
           level() < pc.level();
}

AbstractPc& AbstractPc::operator = (const AbstractPc& pc)
{
    (MetaData&)*this = pc;
    return *this;
}

