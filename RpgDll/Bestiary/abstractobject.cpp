#include "abstractobject.h"


AbstractObject::AbstractObject(): QObject(nullptr)
{
	setId(QUuid());
	setName(QString());
}

AbstractObject::AbstractObject(const AbstractObject& ao): QObject(nullptr), MetaData(ao)
{
    
}

AbstractObject::~AbstractObject()
{
    
}

QString AbstractObject::name() const
{
    return metaData<QString>("name");
}

void AbstractObject::setName(const QString &name)
{
    setMetadata("name", name);
    emit s_name(name);
}

bool AbstractObject::operator <(const AbstractObject& ao) const
{
    return name() < ao.name();    
}

bool AbstractObject::operator ==(const AbstractObject& ao) const
{
    return id() == ao.id();
}

AbstractObject& AbstractObject::operator =(const AbstractObject& ao)
{
    MetaData::operator =(ao);
    return *this;
}
