#ifndef ITEMIMPL_H
#define ITEMIMPL_H

#include "abstractobject.h"

class ItemImpl: public AbstractObject
{
public:
    ItemImpl() = default;
    ~ItemImpl() = default;

    static ObjectPointer create();
};

#endif // ITEMIMPL_H
