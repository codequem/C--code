#include "CashFactory.h"
#include "CashNormal.h"
#include "CashRebate.h"
#include "CashReturn.h"
#include "CashContext.h"
#include <iostream>

int main(void)
{
    //CashSuper *c = new CashSuper()
    //CashSuper * cashsuper = nullptr;    
    //cashsuper = CashFactory::i("normal");
    //std::cout<< (*cashsuper).acceptCash(100)<<std::endl;
    //delete cashsuper;

    //cashsuper = CashFactory::i("rebate");
    //CashRebate* cashrebate = dynamic_cast<CashRebate*>(cashsuper);
    //(*cashrebate).setRebate(0.8);
    //std::cout << (*cashrebate).acceptCash(100) << std::endl;
    //delete cashsuper;

    //cashsuper = CashFactory::i("return");
    //CashReturn *cashreturn = dynamic_cast<CashReturn*>(cashsuper);
    //(*cashreturn).setCondition(30);
    //(*cashreturn).setReturn(5);
    //std::cout << (*cashrebate).acceptCash(100) << std::endl;

    CashContext cashContext("normal");
    //CashContext cashContext("rebate");
    //CashContext cashContext("return");

    //cashContext = CashContext(new CashRebate(0.8));
    //cashContext = CashContext(new CashReturn(30,5));
    std::cout << cashContext.ContextInterface(100) << std::endl;

    return 0;
}