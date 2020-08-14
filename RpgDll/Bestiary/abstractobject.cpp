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
    return MetaData::metaData<QUuid>("id");
}

void AbstractObject::setId(QUuid i)
{
    MetaData::setMetadata("id", i);
}

QString AbstractObject::name() const
{
    return MetaData::metaData<QString>("name");
}

void AbstractObject::setName(const QString &name)
{
    MetaData::setMetadata("name", name);
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

void AbstractObject::setMetadata(QString key, QString value)
{
        QSet<QString> keys;
        keys<<"name"<<"id";
        if(keys.contains(key))
            return;

        MetaData::setMetadata(key, value);
        emit s_metadata(key, value);
}

QString AbstractObject::metaData(QString key) const
{
    return MetaData::metaData<QString>(key);
}

QStringList AbstractObject::metadataList() const
{
    QStringList ret = MetaData::metadataList();
    ret.removeAll("id");
    ret.removeAll("name");
    return ret;
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

