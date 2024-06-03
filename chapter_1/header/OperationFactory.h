#pragma once
#include "Operation.h"

class OperationFactory
{
public:
    static Operation* i(char oper);
};