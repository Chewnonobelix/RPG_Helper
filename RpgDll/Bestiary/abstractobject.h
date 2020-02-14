#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <QObject>
#include <typeinfo>
#include <QDebug>

#include "Bestiary_global.h"

class BESTIARY_EXPORT AbstractObject: public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY s_name)
    
private:
    QString m_name;
    
public:
    AbstractObject();
    AbstractObject(const AbstractObject& ao);
    ~AbstractObject() = 0;

   
    virtual bool operator <(const AbstractObject&) const;
    virtual bool operator ==(const AbstractObject&) const;
    virtual AbstractObject& operator =(const AbstractObject&);
    
    QString name() const;
    void setName(const QString &name);

signals:
    void s_name(QString);
};

typedef QSharedPointer<AbstractObject> ObjectPointer;
#endif // ABSTRACTOBJECT_H
