#include "ConcreteDecorator_2.h"
#include <iostream>

void ConcreteDecorator_2::Operation()
{
    Decorator::Operation();
    std::cout << "ConcreteDecorator_2::Operation()" << std::endl;
}