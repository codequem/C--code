#include <iostream>
using std::cout;
using std::cin;
void fun(int a,int b);

int main (void)
{
    int * P;
    int arr[4][5];
    P=arr[0];
    arr[2][3]=*(*(P+2)+3);
}