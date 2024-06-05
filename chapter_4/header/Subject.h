#pragma once 

class Subject
{
public:
    Subject() = default;
    virtual ~Subject() = default;
    virtual void Request() = 0;
};