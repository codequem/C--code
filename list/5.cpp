#include <iostream>
#include <cstdio>
using namespace std;


int main (void)
{
    int nums;
    cin>>nums;
    int array1[nums];
    int array2[nums];
    array1[0]=1;
    array1[1]=2;
    array2[0]=2;
    array2[1]=3;
    for(int i=2;i<nums;i++)
        array1[i]=array1[i-1]+array1[i-2];
    for(int i=2;i<nums;i++)
        array2[i]=array2[i-1]+array2[i-2];
    double answer=0;
    for(int i=0;i<nums;i++)
    {
        answer+=double(array2[i])/double(array1[i]);
    }
    printf("%.2f",answer);
}

