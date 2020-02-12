#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <QObject>

class AbstractObject: public QObject
{
    Q_OBJECT
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
};

#endif // ABSTRACTOBJECT_H
