#include <iostream>
#include <cmath>

using namespace std;
typedef struct node{
    double posi;
    double rad;
    double l;
    double r;
}node;

int main (void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        double l,w;
        cin>>n>>l>>w;
        node mach[n];
        for(int i=0;i<n;i++)
        {
            cin>>mach[i].posi>>mach[i].rad;
            double d_ava=sqrt(mach[i].rad*mach[i].rad-w*w/4);
            mach[i].l=mach[i].posi-d_ava;
            mach[i].r=mach[i].posi+d_ava;
        }
        
    }
    return 0;
}