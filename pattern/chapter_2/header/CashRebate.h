#pragma once
#include "CashSuper.h"

class CashRebate:public CashSuper
{
private:
    double moneyRebate = 1.0;
public:
    void setRebate(double Rebate = 1.0);
    double acceptCash(double money);
};