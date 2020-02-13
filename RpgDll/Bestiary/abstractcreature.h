#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <QObject>
#include "metadata.h"

class AbstractCreature: public QObject, private MetaData
{
    Q_OBJECT
    
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY s_name)
    Q_PROPERTY(QString race READ race WRITE setRace NOTIFY s_race)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY s_description)
    Q_PROPERTY(QStringList characteristicsList READ characteristicsList CONSTANT)
    
protected:
    
public:
    AbstractCreature();
    AbstractCreature(const AbstractCreature&);
    ~AbstractCreature() = 0;
    
    virtual AbstractCreature& operator = (const AbstractCreature&);
    virtual bool operator == (const AbstractCreature&) const;
    virtual bool operator < (const AbstractCreature&) const;
    
    QString name() const;
    void setName(QString);
    QString race() const;
    void setRace(QString);
    QString description() const;
    void setDescription(QString);
    QStringList characteristicsList() const;
    double characteristics(QString);
    void setCharacteristics(QString, double);
    
signals:
     void s_name(QString);
     void s_race(QString);
     void s_description(QString);
     void s_characteristics(QString, double);
};

#endif // ABSTRACTCREATURE_H
