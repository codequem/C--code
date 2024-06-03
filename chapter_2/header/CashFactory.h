#pragma once
#include "CashSuper.h"
#include <string>

class CashFactory
{
private:
public:
    static CashSuper *i(std::string mode);
};
