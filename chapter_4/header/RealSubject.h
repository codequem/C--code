#pragma once
#include "Subject.h"

class RealSubject : public Subject
{
public:
    RealSubject() = default;
    ~RealSubject() = default;
    void Request() override;
};