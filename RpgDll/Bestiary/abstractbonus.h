#ifndef ABSRACTBONUS_H
#define ABSRACTBONUS_H

#include <QObject>
#include "Bestiary_global.h"
#include "metadata.h"

class BESTIARY_EXPORT AbstractBonus : public QObject, protected MetaData
{
    Q_OBJECT
    
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY s_name)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY s_description)
    
public:
    AbstractBonus();
    AbstractBonus(const AbstractBonus&);
    ~AbstractBonus() = 0;
    
    virtual AbstractBonus& operator =(const AbstractBonus&);
    virtual bool operator ==(const AbstractBonus&) const;
    virtual bool operator <(const AbstractBonus&) const;
    
    QString name() const;
    void setName(QString);
    
    QString description() const;
    void setDescription(QString);
    
signals:
    void s_name(QString);
    void s_description(QString);
};

#endif // ABSRACTBONUS_H
