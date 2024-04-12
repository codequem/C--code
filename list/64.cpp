#include <iostream>

using namespace std;

int main (void)
{
    long i = 1;
    for (int j=0;j<2023;j++)
    {
        i*=2;
        i %= 1000;
    }
    cout<<i<<endl;
    return 0;
}