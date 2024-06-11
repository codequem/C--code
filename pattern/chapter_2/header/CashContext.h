#pragma once
#include "CashSuper.h"
#include "CashFactory.h"

#include <string>

class CashContext
{
private:
    CashSuper *cashsuper;

public:
    CashContext(std::string mode)
    {
        cashsuper = CashFactory::i(mode);
    }
    CashContext(const CashContext &cashContext)
    {
        cashsuper = cashContext.cashsuper;
    };
    ~CashContext()
    {
        if (cashsuper != nullptr)
            delete cashsuper;
        cashsuper = nullptr;
    };
    CashContext &operator=(const CashContext &cls)
    {
        if (this != &cls)
        {
            if (cashsuper != nullptr)
            {
                delete cashsuper;
                cashsuper = nullptr;
            }
        }
        cashsuper = cls.cashsuper;
        return *this;
    }

    double ContextInterface(double money);
};
