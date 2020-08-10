#include "abstractobject.h"


AbstractObject::AbstractObject(): QObject(nullptr)
{
    
}

AbstractObject::AbstractObject(const AbstractObject& ao): QObject(nullptr), m_name(ao.name())
{
    
}

AbstractObject::~AbstractObject()
{
    
}

QString AbstractObject::name() const
{
    return m_name;
}

void AbstractObject::setName(const QString &name)
{
    m_name = name;
    emit s_name(m_name);
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
