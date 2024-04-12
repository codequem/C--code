#include <iostream>
using namespace std;

void foo(int a, int b, int c = 1)
{
    if (c == 1)
        cout << a / b << endl;
    else if (c == 2)
        cout << a % b << endl;
    else
        cout << (float)a / b << endl;
}

int main()
{
    foo(3, 4);
    foo(3, 4, 1);
    foo(3, 4, 2);
    foo(3, 4, 3);
    return 0;
}
