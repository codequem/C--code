#include <iostream>
using namespace std;

class Circle
{
private:
    double r;
    const double pi = 3.1415926;

public:
    Circle(int r = 0) : r(r) {}
    double area() const { return r * r * pi; }
    double girth() const { return 2 * r * pi; }
};

int main(void)
{
    Circle C(3);
    cout<<"C:area:"<<C.area()<<",girth:"<<C.girth()<<endl;
    return 0;
}