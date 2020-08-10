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
    
QUuid AbstractCreature::id() const
{
	return metaData<QUuid>("id");
}

void AbstractCreature::setId(QUuid i)
{
	setMetadata("id", i);
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
    auto map = metaData<QVariant>("item").toMap();
    
    return map.keys();
}

QSet<ObjectPointer> AbstractCreature::itemSet(QString name) const
{
    auto map = metaData<QVariant>("item").toMap();
    return map[name].value<QSet<ObjectPointer>>();    
}

void AbstractCreature::setItem(QString name, ObjectPointer obj)
{
    auto map = metaData<QVariant>("item").toMap();
    auto set = map[name].value<QSet<ObjectPointer>>();
    set<<obj;
    map[name] = QVariant::fromValue(set);
    setMetadata("item", map);
    emit s_object(name, obj);
}

QStringList AbstractCreature::ruleTypeList() const
{
    return QStringList();
}

QSet<BonusPointer> AbstractCreature::ruleSet(QString) const
{
    return QSet<BonusPointer>();
}

void AbstractCreature::setRule(QString, BonusPointer)
{

}
