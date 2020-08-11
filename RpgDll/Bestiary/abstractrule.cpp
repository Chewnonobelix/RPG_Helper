#include "abstractrule.h"

AbstractRule::AbstractRule() : QObject(nullptr)
{
	setId(QUuid());
	setName(QString());
}

AbstractRule::AbstractRule(const AbstractRule& ab): QObject(nullptr), MetaData(ab)
{}

AbstractRule::~AbstractRule() {}

AbstractRule& AbstractRule::operator =(const AbstractRule& ab)
{
    MetaData::operator =(ab);
    return *this;
}

bool AbstractRule::operator ==(const AbstractRule& ab) const 
{    
    return id() == ab.id();
}

bool AbstractRule::operator <(const AbstractRule& ab) const
{   
    return name() < ab.name();
}

QUuid AbstractRule::id() const
{
	return metaData<QUuid>("id");
}

void AbstractRule::setId(QUuid i)
{
	setMetadata("id", i);
}

QString AbstractRule::name() const
{
    return metaData<QString>("name");
}

void AbstractRule::setName(QString n) 
{
    setMetadata("name", n);
    emit s_name(name());
}

QString AbstractRule::description() const
{
    return metaData<QString>("description");
}

void AbstractRule::setDescription(QString d)
{
    setMetadata("description", d);
    emit s_description(description());
}

class GenericRule: public AbstractRule
{
public:
    GenericRule() = default;
    GenericRule(const GenericRule&) = default;
    ~GenericRule() = default;
};

RulePointer AbstractRule::createGeneric()
{
    return DesignPattern::factory<GenericRule>();
}

RulePointer AbstractRule::createGeneric(const AbstractRule& ar)
{
    return DesignPattern::factory<GenericRule>(dynamic_cast<const GenericRule&>(ar));
}
