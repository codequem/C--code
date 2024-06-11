#include <iostream>
using namespace std;

class Operation
{
private:
    double numberA = 0;
    double numberB = 0;

public:
    const Operation& operator=(const Operation& other)
    {
        numberA = other.numberA;
        numberB = other.numberB;
        return *this;
    }
    double get_NumberA() const
    {
        return numberA;
    }
    double get_NumberB() const
    {
        return numberB;
    }
    double set_NumberA(double value)
    {
        numberA = value;
        return numberA;
    }
    double set_NumberB(double value)
    {
        numberB = value;
        return numberB;
    }
    virtual double get_result()
    {
        double result = 0;
        return result;
    }
};

class OperationAdd : public Operation
{
public:
    double get_result() override
    {
        double result = 0;
        result = get_NumberA() + get_NumberB();
        return result;
    }
};

class OperationSub : public Operation
{
public:
    double get_result() override
    {
        double result = 0;
        result = get_NumberA() - get_NumberB();
        return result;
    }
};

class OperationMul : public Operation
{
public:
    double get_result() override
    {
        double result = 0;
        result = get_NumberA() * get_NumberB();
        return result;
    }
};

class OperationDiv : public Operation
{
public:
    double get_result() override
    {
        double result = 0;
        if (get_NumberB() == 0)
        {
            cout << "除数不能为0！" << endl;
        }
        result = get_NumberA() / get_NumberB();
        return result;
    }
};

class OperationFactory
{
public:
    static Operation& createOperate(int operate)
    {
        Operation *oper = nullptr;
        switch (operate)
        {
        case 1:
            oper = new OperationAdd();
            break;
        case 2:
            oper = new OperationSub();
            break;
        case 3:
            oper = new OperationMul();
            break;
        case 4:
            oper = new OperationDiv();
            break;
        }
        return *oper;
    }
};

int main()
{
    Operation *oper = new Operation();
    *oper = OperationFactory::createOperate(1);
    oper->set_NumberA(1);
    oper->set_NumberB(1);
    double result = oper->get_result();

    cout << result << endl;

    return 0;
}