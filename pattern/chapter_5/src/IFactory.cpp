#include "IFactory.h"

IOperation* AddFactory::CreateOperation()
{
    return new Add();
}

IOperation* SubFactory::CreateOperation()
{
    return new Sub();
}

IOperation* MulFactory::CreateOperation()
{
    return new Mul();
}

IOperation* DivFactory::CreateOperation()
{
    return new Div();
}