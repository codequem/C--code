#include "Operation.h"

Operation::~Operation() {}

double Operation::getNumberA()
{
    return _numberA;
}
double Operation::getNumberB()
{
    return _numberB;
}
void Operation::setNumberA(double value)
{
    _numberA = value;
}

void Operation::setNumberB(double value)
{
    _numberB = value;
}