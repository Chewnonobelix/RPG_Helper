#ifndef RULEIMPL_H
#define RULEIMPL_H

#include <QSharedPointer>
#include "abstractrule.h"

class RuleImpl: public AbstractRule
{
public:
    RuleImpl() = default;
    ~RuleImpl() = default;

    static RulePointer create();
};

#endif // RULEIMPL_H
