#include "CashFactory.h"
#include "CashNormal.h"
#include "CashRebate.h"
#include "CashReturn.h"
#include <iostream>

int main(void)
{
    CashSuper * cashsuper = nullptr;    
    cashsuper = CashFactory::i("normal");
    std::cout<< (*cashsuper).acceptCash(100)<<std::endl;
    delete cashsuper;

    cashsuper = CashFactory::i("rebate");
    CashRebate* cashrebate = dynamic_cast<CashRebate*>(cashsuper);
    (*cashrebate).setRebate(0.8);
    std::cout << (*cashrebate).acceptCash(100) << std::endl;
    delete cashsuper;

    cashsuper = CashFactory::i("return");
    CashReturn *cashreturn = dynamic_cast<CashReturn*>(cashsuper);
    (*cashreturn).setCondition(30);
    (*cashreturn).setReturn(5);
    std::cout << (*cashrebate).acceptCash(100) << std::endl;

    return 0;
}