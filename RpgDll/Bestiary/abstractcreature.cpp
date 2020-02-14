#include "abstractcreature.h"

QSet<QString> AbstractCreature::uncharacteristic = QSet<QString>({"name", "race", "description"});

AbstractCreature::AbstractCreature(): QObject(nullptr)
{
    
}

AbstractCreature::AbstractCreature(const AbstractCreature& ac): QObject(nullptr), MetaData(ac)
{}

AbstractCreature::~AbstractCreature()
{}

AbstractCreature& AbstractCreature::operator = (const AbstractCreature& ac)
{
    MetaData::operator =(ac);
    return *this;
}

bool AbstractCreature::operator == (const AbstractCreature& ac) const
{
    bool ret = true;
    for(auto it: metadataList())
        ret &= metaData<QVariant>(it) == ac.metaData<QVariant>(it);
    
    return ret;
}

bool AbstractCreature::operator < (const AbstractCreature& ac) const
{
    bool ret = false;
    for(auto it: metadataList())
        ret |= metaData<QVariant>(it) < ac.metaData<QVariant>(it);
    
    return ret;
}

QString AbstractCreature::name() const
{
    return metaData<QString>("name");
}

void AbstractCreature::setName(QString n)
{
    setMetadata("name", n);
    emit s_name(name());
}

QString AbstractCreature::race() const
{
    return metaData<QString>("race");
}

void AbstractCreature::setRace(QString r)
{    
    setMetadata("race", r);
    emit s_race(race());
}

QString AbstractCreature::description() const
{
    return metaData<QString>("description");
}

void AbstractCreature::setDescription(QString d)
{
    setMetadata("description", d);
    emit s_description(description());    
}

QStringList AbstractCreature::characteristicsList() const
{
    auto ret = metadataList().toSet();
    ret -= uncharacteristic;
    return ret.values();
}

double AbstractCreature::characteristics(QString name)
{
    return metaData<double>(name);
}

void AbstractCreature::setCharacteristics(QString name, double value)
{
    if(!uncharacteristic.contains(name))
    {
        setMetadata(name, value);
        emit s_characteristics(name, characteristics(name));
    }
}

QStringList AbstractCreature::itemTypeList() const
{
    return QStringList();
}

QSet<ObjectPointer> AbstractCreature::itemSet(QString) const
{
    return QSet<ObjectPointer>();    
}

void AbstractCreature::setItem(QString, ObjectPointer)
{}
