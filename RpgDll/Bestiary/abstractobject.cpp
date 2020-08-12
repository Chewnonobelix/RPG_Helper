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

QUuid AbstractObject::id() const
{
        return metaData<QUuid>("id");
}

void AbstractObject::setId(QUuid i)
{
	setMetadata("id", i);
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

class GenericObject: public AbstractObject
{
public:
    GenericObject() = default;
    GenericObject(const GenericObject&) = default;
    ~GenericObject() = default;
};

ObjectPointer AbstractObject::createGeneric()
{
    return DesignPattern::factory<GenericObject>();
}

ObjectPointer AbstractObject::createGeneric(const AbstractObject& ao)
{
    return DesignPattern::factory<GenericObject>(dynamic_cast<const GenericObject&>(ao));
}

