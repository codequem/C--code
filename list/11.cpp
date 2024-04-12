#include <iostream>
#include <vector>
#define N 10005
#define eps 1e-6
using namespace std;

bool check(double x,int k,int n);

double arr[N]={0};
int main (void)
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    double l=0,r=1e5;
    double ans;
    while(r-l>eps)
    {
        double mid=(r+l)/2;
        if(mid==0) break;
        if(check(mid,k,n)){
            ans=mid;
            l=mid;
        }
        else r=mid;
    }
    r=int(r*100);
    r/=100;
    printf("%.2f\n",r);
    return 0;
}

bool check(double x,int k,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=(arr[i]/x);
    }
    return sum>=k;
}