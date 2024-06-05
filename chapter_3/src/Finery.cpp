#include "Finery.h"
#include <iostream>

void Finery::decorate(Person *component)
{
    this->component = component;
}

void Finery::show() const
{
    if (component != nullptr)
    {
        component->show();
    }
}

void TShirt::show() const
{
    std::cout << "Wear T-Shirt " << std::endl;
    Finery::show();
}

void BigTrouser::show() const
{
    std::cout << "Wear Big Trouser " << std::endl;
    Finery::show();
}

void Sneakers::show() const
{
    std::cout << "Wear Sneakers " << std::endl;
    Finery::show();
}

void Suit::show() const
{
    std::cout << "Wear Suit " << std::endl;
    Finery::show();
}