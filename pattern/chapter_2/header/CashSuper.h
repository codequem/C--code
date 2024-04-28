#pragma once

class CashSuper
{
private:
    
public:
    CashSuper() = default;
    ~CashSuper();
    virtual double acceptCash()
    {
        double SumCash = 0;
        return SumCash;
    }
};

CashSuper::CashSuper()
{
}

CashSuper::~CashSuper()
{
}
