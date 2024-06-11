#pragma once
#include "Subject.h"
#include <iostream>
#include <string>

class RealSubject : public Subject
{
private:
    std::string name = "unknown";
public:
    RealSubject() = default;
    RealSubject(std::string name) : name(name) {}
    ~RealSubject() = default;
    void Request() override;
};