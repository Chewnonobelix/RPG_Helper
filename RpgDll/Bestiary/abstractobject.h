#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <QObject>
#include <typeinfo>
#include <QDebug>
#include <QUuid>
#include "metadata.h"

#include "Bestiary_global.h"

class BESTIARY_EXPORT AbstractObject: public QObject, protected MetaData
{
    Q_OBJECT
    
	Q_PROPERTY(QUuid id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY s_name)
    
private:
    
public:
    AbstractObject();
    AbstractObject(const AbstractObject& ao);
    ~AbstractObject() = 0;

   
    virtual bool operator <(const AbstractObject&) const;
    virtual bool operator ==(const AbstractObject&) const;
    virtual AbstractObject& operator =(const AbstractObject&);
    
	QUuid id() const;
	void setId(QUuid);
    QString name() const;
    void setName(const QString &name);

signals:
    void s_name(QString);
};

typedef QSharedPointer<AbstractObject> ObjectPointer;
#endif // ABSTRACTOBJECT_H
