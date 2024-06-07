#include "IOperation.h"

double IOperation::getNumberA()
{
    return _numberA;
}
double IOperation::getNumberB()
{
    return _numberB;
}
void IOperation::setNumberA(double value)
{
    _numberA = value;
}

void IOperation::setNumberB(double value)
{
    _numberB = value;
}

double Add::GetResult()
{
    return getNumberA() + getNumberB();
}

double Sub::GetResult()
{
    return getNumberA() - getNumberB();
}

double Mul::GetResult()
{
    return getNumberA() * getNumberB();
}

double Div::GetResult()
{
    if (getNumberB() == 0)
    {
        throw "除数不能为0";
    }
    return getNumberA() / getNumberB();
}
