#include <iostream>
#include <cstdio>
#define N 100050

using namespace std;

int f[N][21],lg[N];

void init(int n);
int query(int l,int r);

int main (void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%d",&f[i][0]);
    init(n);
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query(l,r));
    }
    return 0;
}

void init(int n)
{
    for(int i=2;i<=n;i++)
    lg[i]=lg[i-1]+!(i&(i-1));
    for(int j=1;j<=lg[n];j++)
        for(int i=1;i+(1<<j)-1<=n;i++)//这里是枚举起点
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

int query(int l,int r)
{
    int k=lg[r-l+1];
    return max(f[l][k],f[r-(1<<k)+1][k]);
}