//N皇后问题
#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;
const int maxn = 30;
int ans[maxn];
int answer;
bool useline[maxn];//记录已经使用过的行，列不需要记录，因为本来就是一列一列找下去
bool useldiag[maxn];//记录已经使用过的左对角线
bool userdiag[maxn];//记录已经使用过的右对角线
int n;//N*N的棋盘
int sum=0;

void dfs(int depth);

int main (void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
    useldiag[i]=useline[i]=userdiag[i]=false;
    dfs(1);
    cout<<answer;
    system("pause");
    return 0;
}

void dfs(int depth)//行
{
    if(depth==n+1)
    {
        answer++;
        sum++;
        if(sum<=3)
        {
            for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
            cout<<endl;
        }
    }
    for(int i=1;i<=n;i++)//列
    {
        if((!useline[i])&&(!useldiag[i+depth-1])&&(!userdiag[n-i+depth]))
        {
            useline[i]=useldiag[i+depth-1]=userdiag[n-i+depth]=true;
            if(sum!=3)
                ans[depth]=i;
            dfs(depth+1);
            useline[i]=useldiag[i+depth-1]=userdiag[n-i+depth]=false;
        }
    }
}   