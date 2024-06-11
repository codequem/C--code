#pragma once 
#include "IOperation.h"

class IFactory
{
public:
    virtual ~IFactory() {}
    virtual IOperation *CreateOperation() = 0;
};

class AddFactory : public IFactory
{
public:
    IOperation* CreateOperation() override;
};

class SubFactory : public IFactory
{
public:
    IOperation* CreateOperation() override;
};

class MulFactory : public IFactory
{
public:
    IOperation* CreateOperation() override;
};

class DivFactory : public IFactory
{
public:
    IOperation* CreateOperation() override;
};