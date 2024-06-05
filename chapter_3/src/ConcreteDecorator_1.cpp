#include "ConcreteDecorator_1.h"
#include <iostream>

void ConcreteDecorator_1::Operation()
{
    Decorator::Operation();//调用基类的方法
    AddedBehavior();
    std::cout << "ConcreteDecorator_1::Operation()" << std::endl;
}

void ConcreteDecorator_1::AddedBehavior()
{
    addedState = "ConcreteDecorator_1::New State";
    std::cout << addedState << std::endl;
}