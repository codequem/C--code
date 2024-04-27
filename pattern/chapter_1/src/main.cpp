#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"

#include <iostream>

int main()
{
    Add A;
    A.setNumberA(2);
    A.setNumberB(3);
    std::cout << A.GetResult();

    Sub S;
    S.setNumberA(2);
    S.setNumberB(3);
    std::cout << S.GetResult();

    Mul M;
    M.setNumberA(2);
    M.setNumberB(3);
    std::cout << M.GetResult();

    Div D;
    D.setNumberA(2);
    D.setNumberB(3);
    std::cout << D.GetResult();

    return 0;
}