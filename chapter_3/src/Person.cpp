#include "Person.h"
#include <iostream>

void Person::show() const
{
    std::cout << "Person: " << name << std::endl;
}
