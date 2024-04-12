#include <iostream>
#define N 1050

using namespace std;
void insert(int x1,int y1,int x2,int y2,int c,int (&floor)[N][N]);

int main (void)
{
    int n,m;
    int x1,y1,x2,y2;
    cin>>n>>m;
    int floor[N][N]={0};
    int sum[N][N]={0};
    while(m--)
    {
        cin>>x1>>y1>>x2>>y2;
        insert(x1,y1,x2,y2,1,floor);
    }
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=n+1;j++)
        {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+floor[i-1][j-1];
            if(i>=2&&j>=2)
            {
                cout<<sum[i][j]<<' ';
                if(j==n+1)
                cout<<endl;
            }
        }
}

void insert(int x1,int y1,int x2,int y2,int c,int (&floor)[N][N])
{
    floor[x1][y1] += c;
    floor[x2 + 1][y1] -= c;
    floor[x1][y2 + 1] -= c;
    floor[x2 + 1][y2 + 1] += c;
}