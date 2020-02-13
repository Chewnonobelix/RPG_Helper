#include "abstractcreature.h"

AbstractCreature::AbstractCreature()
{
    
}

AbstractCreature::AbstractCreature(const AbstractCreature&): QObject(nullptr), MetaData()
{}

AbstractCreature& AbstractCreature::operator = (const AbstractCreature&)
{
    return *this;
}

bool AbstractCreature::operator == (const AbstractCreature&) const
{
    return false;
}

bool AbstractCreature::operator < (const AbstractCreature&) const
{
    return false;
}

QString AbstractCreature::name() const
{
    return "";
}

void AbstractCreature::setName(QString)
{}

QString AbstractCreature::race() const
{
    return "";
}

void AbstractCreature::setRace(QString)
{}

QString AbstractCreature::description() const
{
    return "";
}

void AbstractCreature::setDescription(QString)
{}

QStringList AbstractCreature::characteristicsList() const
{
    return QStringList();    
}

double AbstractCreature::characteristics(QString)
{
    return -1;
}

void AbstractCreature::setCharacteristics(QString, double)
{}
