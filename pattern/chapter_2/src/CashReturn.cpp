#include "CashReturn.h"

void CashReturn::setCondition(double Condition)
{
    moneyCondition = Condition;
}

void CashReturn::setReturn(double Return)
{
    moneyReturn = Return;
}

double CashReturn::acceptCash(double money)
{
    double result = money;
    if (money >= moneyCondition)
        result = money - static_cast<int>(money / moneyCondition) * moneyReturn;
    return result;
}