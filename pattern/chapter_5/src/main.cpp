#include "IFactory.h"
#include <iostream>


int main(void)
{
    IFactory* factory = new AddFactory();
    IOperation* operation = factory->CreateOperation();
    operation->setNumberA(1);
    operation->setNumberB(2);
    std::cout << operation->GetResult() << std::endl;
    return 0;
}