#include "abstractbonus.h"

AbstractBonus::AbstractBonus() : QObject(nullptr)
{
    
}

AbstractBonus::AbstractBonus(const AbstractBonus&): QObject(nullptr)
{}

AbstractBonus::~AbstractBonus() {}

AbstractBonus& AbstractBonus::operator =(const AbstractBonus&)
{
    return *this;
}

bool AbstractBonus::operator ==(const AbstractBonus&) const 
{
    return false;
}

bool AbstractBonus::operator <(const AbstractBonus&) const
{
    return false;
}

QString AbstractBonus::name() const
{
    return "";
}

void AbstractBonus::setName(QString) {}

QString AbstractBonus::description() const
{
    return "";
}

void AbstractBonus::setDescription(QString)
{}
