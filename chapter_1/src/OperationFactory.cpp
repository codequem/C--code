#include "OperationFactory.h"
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"

Operation* OperationFactory::i(char oper)
{
    Operation *instance = nullptr;
    switch (oper)
    {
    case '+':
        instance = new Add();
        break;
    case '-':
        instance = new Sub();
        break;
    case '*':
        instance = new Mul();
        break;
    case '/':
        instance = new Div();
        break;
    }
    return instance;
};