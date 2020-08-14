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
    return MetaData::metaData<QUuid>("id");
}

void AbstractRule::setId(QUuid i)
{
    MetaData::setMetadata("id", i);
}

QString AbstractRule::name() const
{
    return MetaData::metaData<QString>("name");
}

void AbstractRule::setName(QString n) 
{
    MetaData::setMetadata("name", n);
    emit s_name(name());
}

QString AbstractRule::description() const
{
    return MetaData::metaData<QString>("description");
}

void AbstractRule::setDescription(QString d)
{
    MetaData::setMetadata("description", d);
    emit s_description(description());
}

void AbstractRule::setMetadata(QString key, QString value)
{
//    QSet<QString> keys;
//    keys<<"description"<<"name"<<"id";
//    if(keys.contains(key))
//        return;

//    MetaData::setMetadata(key, value);
//    emit s_metadata(key, value);
}

QString AbstractRule::metaData(QString) const
{
    return QString();
}

QStringList AbstractRule::metadataList() const
{
    return QStringList();
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
