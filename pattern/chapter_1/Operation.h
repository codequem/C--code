class Operation
{
private:
    double _numberA = 0;
    double _numberB = 0;

public:
    Operation();
    ~Operation();
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
