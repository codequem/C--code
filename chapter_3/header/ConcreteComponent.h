#pragma once
#include "Component.h" 

class ConcreteComponent: public Component
{
public:
    ConcreteComponent() = default;
    void Operation() override;
};