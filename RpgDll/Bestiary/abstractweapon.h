#ifndef ABSTRACTWEAPON_H
#define ABSTRACTWEAPON_H

#include "abstractobject.h"

class AbstractWeapon : public AbstractObject
{
    Q_OBJECT
    
    Q_PROPERTY(QString damage READ damage WRITE setDamage NOTIFY s_damage)
    
private:
    QString m_damage;
    
public:
    AbstractWeapon();
    AbstractWeapon(const AbstractWeapon &);
    
    AbstractWeapon& operator =(const AbstractObject&) override;
    bool operator < (const AbstractObject&) const override;
    bool operator == (const AbstractObject&) const override;
    
    QString damage () const;
    void setDamage(QString);
    
signals:
    void s_damage(QString);
};

#endif // ABSTRACTWEAPON_H
