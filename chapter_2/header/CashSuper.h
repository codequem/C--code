#pragma once

class CashSuper
{
private:
public:
    CashSuper() = default;
    virtual ~CashSuper(){};
    virtual double acceptCash(double money) = 0;
};
