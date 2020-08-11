#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <QObject>
#include <QSet>
#include <QUuid>
#include "designpattern.h"
#include "metadata.h"
#include "Bestiary_global.h"
#include "abstractweapon.h"
#include "abstractrule.h"

class BESTIARY_EXPORT AbstractCreature: public QObject, protected MetaData
{
    Q_OBJECT
    
	Q_PROPERTY(QUuid id READ id CONSTANT)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY s_name)
    Q_PROPERTY(QString race READ race WRITE setRace NOTIFY s_race)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY s_description)
    Q_PROPERTY(QStringList characteristicsList READ characteristicsList CONSTANT)
    Q_PROPERTY(QStringList itemCategory READ itemTypeList CONSTANT)
    Q_PROPERTY(QStringList ruleCategory READ ruleTypeList CONSTANT)
    
protected:
    static QSet<QString> uncharacteristic;
    
public:
    AbstractCreature();
    AbstractCreature(const AbstractCreature&);
    virtual ~AbstractCreature() = 0;
    
    virtual AbstractCreature& operator = (const AbstractCreature&);
    virtual bool operator == (const AbstractCreature&) const;
    virtual bool operator < (const AbstractCreature&) const;
    
	QUuid id() const;
	void setId(QUuid);
    QString name() const;
    void setName(QString);
    QString race() const;
    void setRace(QString);
    QString description() const;
    void setDescription(QString);
    
    QStringList characteristicsList() const;
    double characteristics(QString);
    void setCharacteristics(QString, double);
    
    QStringList itemTypeList() const;
    Q_INVOKABLE QSet<ObjectPointer> itemSet(QString) const;
    void setItem(QString, ObjectPointer);

    QStringList ruleTypeList() const;
    Q_INVOKABLE QSet<RulePointer> ruleSet(QString) const;
    void setRule(QString, RulePointer);

    static QSharedPointer<AbstractCreature> createGeneric();
    static QSharedPointer<AbstractCreature> createGeneric(const AbstractCreature&);
    
signals:
     void s_name(QString);
     void s_race(QString);
     void s_description(QString);
     void s_characteristics(QString, double);
     void s_object(QString, ObjectPointer);
     void s_rule(QString, RulePointer);
};

typedef QSharedPointer<AbstractCreature> CreaturePointer;

#endif // ABSTRACTCREATURE_H
