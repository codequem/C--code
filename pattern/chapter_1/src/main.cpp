// #include "Add.h"
// #include "Sub.h"
// #include "Mul.h"
// #include "Div.h"
#include "Operation.h"
#include "OperationFactory.h"

#include <iostream>

int main()
{
    // Add A;
    // A.setNumberA(2);
    // A.setNumberB(3);
    // std::cout << A.GetResult() << std::endl;

    // Sub S;
    // S.setNumberA(2);
    // S.setNumberB(3);
    // std::cout << S.GetResult() << std::endl;

    // Mul M;
    // M.setNumberA(2);
    // M.setNumberB(3);
    // std::cout << M.GetResult() << std::endl;

    // Div D;
    // D.setNumberA(2);
    // D.setNumberB(3);
    // std::cout << D.GetResult() << std::endl;

    Operation* oper;
    oper = OperationFactory::i('+');
    oper->setNumberA(2);
    oper->setNumberB(3);
    std::cout << oper->GetResult() << std::endl;

    return 0;
}