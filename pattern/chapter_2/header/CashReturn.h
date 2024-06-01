#pragma once
#include "CashSuper.h"

class CashReturn : public CashSuper
{
private:
    double moneyCondition = 0.0;
    double moneyReturn = 0.0;
public:
    CashReturn(double moneyCondition = 0.0,double moneyReturn = 0.0):moneyCondition(moneyCondition),moneyReturn(moneyReturn){}
    void setCondition(double Condition);
    void setReturn(double Return);
    double acceptCash(double money);
};