#pragma once

#include "Decorator.h"
#include <string>

class ConcreteDecorator_1 : public Decorator
{
private:
    std::string addedState;
    void AddedBehavior();

public:
    ConcreteDecorator_1() = default;
    void Operation() override;
    
};