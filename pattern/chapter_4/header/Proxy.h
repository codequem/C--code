#pragma once 
#include "Subject.h"
#include "RealSubject.h"

class Proxy:public Subject
{ 
private:
    RealSubject * realSubject = nullptr;
public:
    Proxy();
    Proxy(RealSubject * realSubject);
    ~Proxy();
    void Request() override;
    void PreRequest();
    void PostRequest();
};