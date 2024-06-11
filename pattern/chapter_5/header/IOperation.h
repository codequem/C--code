#pragma once 

class IOperation
{
private:
    double _numberA = 0;
    double _numberB = 0;

public:
    IOperation() = default;
    virtual ~IOperation(){ };
    double getNumberA();
    double getNumberB();
    void setNumberA(double value);
    void setNumberB(double value);

    virtual double GetResult()
    {
        double result = 0;
        return result;
    }
};

class Add : public IOperation
{
public:
    double GetResult() override;
};

class Sub : public IOperation
{
public:
    double GetResult() override;
};

class Mul : public IOperation
{
public:
    double GetResult() override;
};

class Div : public IOperation
{
public:
    double GetResult() override;
};