#include "abstractbonus.h"

AbstractBonus::AbstractBonus() : QObject(nullptr)
{
	setId(QUuid());
	setName(QString());
}

AbstractBonus::AbstractBonus(const AbstractBonus& ab): QObject(nullptr), MetaData(ab)
{}

AbstractBonus::~AbstractBonus() {}

AbstractBonus& AbstractBonus::operator =(const AbstractBonus& ab)
{
    MetaData::operator =(ab);
    return *this;
}

bool AbstractBonus::operator ==(const AbstractBonus& ab) const 
{    
    return id() == ab.id();
}

bool AbstractBonus::operator <(const AbstractBonus& ab) const
{   
    return name() < ab.name();
}

QUuid AbstractBonus::id() const
{
	return metaData<QUuid>("id");
}

void AbstractBonus::setId(QUuid i)
{
	setMetadata("id", i);
}

QString AbstractBonus::name() const
{
    return metaData<QString>("name");
}

void AbstractBonus::setName(QString n) 
{
    setMetadata("name", n);
    emit s_name(name());
}

QString AbstractBonus::description() const
{
    return metaData<QString>("description");
}

void AbstractBonus::setDescription(QString d)
{
    setMetadata("description", d);
    emit s_description(description());
}
