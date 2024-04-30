#include "CashFactory.h"
#include "CashNormal.h"
#include "CashRebate.h"
#include "CashReturn.h"

CashSuper *CashFactory::i(std::string mode)
{
    CashSuper *instance = nullptr;
    if (mode == "normal")
    {
        instance = new CashNormal();
    }
    else if (mode == "rebate")
    {
        instance = new CashRebate();
    }
    else if (mode == "return")
    {
        instance = new CashReturn();
    }
    else
    {

    }
    return instance;
}