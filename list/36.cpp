#include <iostream>
#include <algorithm>
#include <map>
int tar;
using namespace std;
int check(int q)
{
    cout<<q<<' ';
    if(q==tar)
    {
        cout<<"对了！";
        return 1;
    }
    return 0;
}

int main (void)
{
    cin>>tar;
    int l=0,r=100;
    while(l<r)//在这个方法里无论如何l,r每次都会改变，不会陷入死循环
    //终止条件为l>r
    {
        
        int mid=l+(r-l)/2;//防止加法导致溢出
        if(l+1==r)
        {
            if(mid<tar) l=mid+1;
            else r=mid-1;
            mid=l+(r-l)/2;
            check(mid);
            break;
        }
        if(check(mid))
        break;
        if(mid<tar) l=mid;
        else r=mid;
    }
    return 0;
}