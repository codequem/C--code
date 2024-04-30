#pragma once

class CashSuper
{
private:
public:
    CashSuper() = default;
    ~CashSuper(){};
    virtual double acceptCash(double money)
    {
        return 0;
    }
};
