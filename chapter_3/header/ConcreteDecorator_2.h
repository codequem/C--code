#pragma once

#include "Decorator.h"

class ConcreteDecorator_2 : public Decorator
{
public:
    ConcreteDecorator_2() = default;
    void Operation() override;
};