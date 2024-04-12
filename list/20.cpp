#include <iostream>
#include <algorithm>
#define N 100050
using namespace std;
long long posi[N];

bool check(long long po,int m,int n);
int main (void)
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    cin>>posi[i];
    sort(posi,posi+n);
    long long r=posi[n-1]-posi[0],l=1;
    long long ans=1;
    while(l<=r)
    {
        long long mid=l+(r-l)/2;
        if(check(mid,m,n))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}

bool check(long long po,int m,int n)
{
    int sum=1;
    long long start=posi[0];
    int s=0;
    while(start+po<=posi[n-1])
    {
        s++;
        if(s==n)
        break;
        if(start+po<=posi[s])
        {
            start=posi[s];
            sum++;
        }
    }
    return sum>=m;
}