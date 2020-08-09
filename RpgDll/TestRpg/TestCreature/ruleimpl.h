#ifndef RULEIMPL_H
#define RULEIMPL_H

#include <QSharedPointer>
#include "abstractbonus.h"

class RuleImpl: public AbstractBonus
{
public:
    RuleImpl() = default;
    ~RuleImpl() = default;

    static BonusPointer create();
};

#endif // RULEIMPL_H
