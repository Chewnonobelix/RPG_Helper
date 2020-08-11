#include "abstractcreature.h"

QSet<QString> AbstractCreature::uncharacteristic = QSet<QString>({"name", "race", "description", "item", "rule", "id"});

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
    return id() == ac.id();
}

bool AbstractCreature::operator < (const AbstractCreature& ac) const
{    
    return name() < ac.name() || race() < ac.race();
}

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
    auto map = metaData<QVariant>("rule").toMap();
    
    return map.keys();
}

QSet<RulePointer> AbstractCreature::ruleSet(QString name) const
{
    auto map = metaData<QVariant>("rule").toMap();
    return map[name].value<QSet<RulePointer>>();    
}

void AbstractCreature::setRule(QString name, RulePointer obj)
{
    auto map = metaData<QVariant>("rule").toMap();
    auto set = map[name].value<QSet<RulePointer>>();
    set<<obj;
    map[name] = QVariant::fromValue(set);
    setMetadata("rule", map);
    emit s_rule(name, obj);
}

class GenericCreature: public AbstractCreature
{
public:
    GenericCreature() = default;
    GenericCreature(const GenericCreature&) = default;
    ~GenericCreature() = default;
};

QSharedPointer<AbstractCreature> AbstractCreature::createGeneric()
{
    return DesignPattern::factory<GenericCreature>();
}

QSharedPointer<AbstractCreature> AbstractCreature::createGeneric(const AbstractCreature& ac)
{
    return DesignPattern::factory<GenericCreature>(dynamic_cast<const GenericCreature&>(ac));
}

