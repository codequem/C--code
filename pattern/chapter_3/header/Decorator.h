#pragma once
#include "Component.h"

class Decorator : public Component
{
protected:
    Component *component;
public:
    Decorator() = default;
    void SetComponent(Component &component);
    void Operation() override;
};