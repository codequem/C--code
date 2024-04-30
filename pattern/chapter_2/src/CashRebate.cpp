#include "CashRebate.h"

void CashRebate::setRebate(double Rebate)
{
    moneyRebate = Rebate;
}

double CashRebate::acceptCash(double money)
{
    return money * moneyRebate;
}