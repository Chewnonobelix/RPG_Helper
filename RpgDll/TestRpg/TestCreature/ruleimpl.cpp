#include "ruleimpl.h"

BonusPointer RuleImpl::create()
{
    return QSharedPointer<RuleImpl>::create();
}
