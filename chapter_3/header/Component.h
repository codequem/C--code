#pragma once

class Component
{
public:
    virtual ~Component() = 0;
    virtual void Operation() = 0;
};