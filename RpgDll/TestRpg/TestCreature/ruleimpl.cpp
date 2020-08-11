#include "ruleimpl.h"

RulePointer RuleImpl::create()
{
    return QSharedPointer<RuleImpl>::create();
}
