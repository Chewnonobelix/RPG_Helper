#include "itemimpl.h"

ObjectPointer ItemImpl::create()
{
    return QSharedPointer<ItemImpl>::create();
}
