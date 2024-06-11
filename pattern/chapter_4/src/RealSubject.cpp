#include "RealSubject.h"
#include <iostream>

void RealSubject::Request()
{
    std::cout << "RealSubject:" << name << std::endl;
    std::cout << "RealSubject::Request()" << std::endl;
}