#include "abstractpc.h"

AbstractPc::AbstractPc() : QObject(), MetaData()
{
        setClasses(QString());
	setLevel(0);
	setCurrentXp(0);
	setTargetXp(0);
}

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

QString AbstractPc::classes() const
{
    return metaData<QString>("classes");
}

void AbstractPc::setClasses(QString c)
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

class GenericPc: public AbstractPc
{
public:
    GenericPc() = default;
    GenericPc(const GenericPc&) = default;
    ~GenericPc() = default;

    void addXp(double);
};

void GenericPc::addXp(double)
{}

QSharedPointer<AbstractPc> AbstractPc::createGeneric()
{
    return DesignPattern::factory<GenericPc>();
}

QSharedPointer<AbstractPc> AbstractPc::createGeneric(const AbstractPc& pc)
{
    return DesignPattern::factory<GenericPc>(dynamic_cast<const GenericPc&>(pc));
}


