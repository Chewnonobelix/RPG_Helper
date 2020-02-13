#include "abstractweapon.h"

AbstractWeapon::AbstractWeapon()
{}

AbstractWeapon::AbstractWeapon(const AbstractWeapon & aw): AbstractObject(aw),
    m_damage(aw.damage())
{}

AbstractWeapon& AbstractWeapon::operator =(const AbstractObject& ao)
{
    try
    {
        const AbstractWeapon& aw = dynamic_cast<const AbstractWeapon&>(ao);
        *this = ao;
        setDamage(aw.damage());
    }
    catch(std::bad_cast bc)
    {
        qDebug()<<"Cannot convert to abstract weapon"<<bc.what();
    }

    return *this;
}

bool AbstractWeapon::operator < (const AbstractObject& ao) const
{
    bool ret = false;
    try
    {
        const AbstractWeapon& aw = dynamic_cast<const AbstractWeapon&>(ao);
        ret = AbstractObject::operator <(ao);
        
        return ret || (damage() < aw.damage());
    }
    catch(std::bad_cast bc)
    {
        qDebug()<<"Cannot convert to abstract weapon"<<bc.what();
        return ret;        
    }
    
}

bool AbstractWeapon::operator == (const AbstractObject& ao) const
{
    bool ret = false;
    try
    {
        const AbstractWeapon& aw = dynamic_cast<const AbstractWeapon&>(ao);
        ret = AbstractObject::operator ==(ao);
        
        return ret && (aw.damage() == damage());
    }
    catch(std::bad_cast bc)
    {
        qDebug()<<"Cannot convert to abstract weapon"<<bc.what();
        return ret;        
    }
    
}

QString AbstractWeapon::damage () const
{
    return m_damage;
}

void AbstractWeapon::setDamage(QString d)
{
    m_damage = d;
    emit s_damage(m_damage);
}
