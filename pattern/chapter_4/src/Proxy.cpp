#include "Proxy.h"
#include <iostream>

Proxy::Proxy()
{
    if(realSubject == nullptr)
    {
        realSubject = new RealSubject();
    }
}

Proxy::Proxy(RealSubject *realSubject)
{
    if(realSubject == nullptr)
    {
        realSubject = new RealSubject();
    }
    this->realSubject = realSubject;
}

Proxy::~Proxy()
{
    if(realSubject != nullptr)
    {
        delete realSubject;
    }
}

void Proxy::Request()
{
    PreRequest();
    realSubject->Request();
    PostRequest();
}

void Proxy::PreRequest()
{
    std::cout << "Proxy::PreRequest()" << std::endl;
}

void Proxy::PostRequest()
{
    std::cout << "Proxy::PostRequest()" << std::endl;
}
