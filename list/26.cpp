//N皇后问题
#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;
const int maxn = 12;
char chessboard[maxn][maxn];//记录棋盘
bool useline[maxn];//记录已经使用过的行，列不需要记录，因为本来就是一列一列找下去
bool useldiag[maxn];//记录已经使用过的左对角线
bool userdiag[maxn];//记录已经使用过的右对角线
int n;//N*N的棋盘
int step=1;

void dfs(int depth);

int main (void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            chessboard[i][j]='.';
    for(int i=1;i<=n;i++)
    useldiag[i]=useline[i]=userdiag[i]=false;
    dfs(step);
    system("pause");
    return 0;
}

void dfs(int depth)//行
{
    if(depth==n+1)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {
                    cout<<chessboard[i][j]<<' ';
                    if(j==n) cout<<endl;
                }
        
    }
    for(int i=1;i<=n;i++)//列
    {
        if((!useline[i])&&(!useldiag[i+depth-1])&&(!userdiag[n-i+depth]))
        {
            useline[i]=useldiag[i+depth-1]=userdiag[n-i+depth]=true;
            chessboard[depth][i]='Q';
            dfs(depth+1);
            chessboard[depth][i]='.';
            useline[i]=useldiag[i+depth-1]=userdiag[n-i+depth]=false;
        }
    }
}   