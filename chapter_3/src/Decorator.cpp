#include "Decorator.h"

void Decorator::SetComponent(Component &component)
{
    this->component = &component;
}

void Decorator::Operation()
{
    if (component != nullptr)
    {
        component->Operation();
    }
}