#include "abstractweapon.h"

AbstractWeapon::AbstractWeapon()
{}

AbstractWeapon::AbstractWeapon(const AbstractWeapon &) 
{}

AbstractWeapon& AbstractWeapon::operator =(const AbstractObject&)
{
    return *this;
}

bool AbstractWeapon::operator < (const AbstractObject&) const
{
    return false;
}

bool AbstractWeapon::operator == (const AbstractObject&) const
{
    return false;
}

QString AbstractWeapon::damage () const
{
    return "";
}

void AbstractWeapon::setDamage(QString)
{}
