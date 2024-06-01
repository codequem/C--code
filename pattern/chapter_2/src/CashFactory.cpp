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
        instance = new CashRebate(0.8);
    }
    else if (mode == "return")
    {
        instance = new CashReturn(30,5);
    }
    else
    {

    }
    return instance;
}