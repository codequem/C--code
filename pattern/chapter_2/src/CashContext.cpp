#include "CashContext.h"

double CashContext::ContextInterface(double money)
{
    return cashsuper->acceptCash(money);
}