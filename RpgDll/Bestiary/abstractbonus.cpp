#include "abstractbonus.h"

AbstractBonus::AbstractBonus() : QObject(nullptr)
{
    
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
    bool ret = true;
    
    for(auto it: metadataList())
        ret &= metaData<QVariant>(it) == ab.metaData<QVariant>(it);
    
    return ret;
}

bool AbstractBonus::operator <(const AbstractBonus& ab) const
{
    bool ret = false;
    
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
