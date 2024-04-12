#include <iostream>
#include <windows.h>

using namespace std;

bool book[15];
int ans[15];
int step=1;
int n;
void dfs(int depth);

int main (void)
{
    for(int i=0;i<10;i++)
    book[i]=false;
    cin>>n;
    dfs(0);
    system("pause");
    return 0;
}

void dfs(int depth)
{
    if(depth==n)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%5d",ans[i]);
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!book[i])
        {
            ans[++depth]=i;
            book[i]=true;
            dfs(depth);
            book[i]=false;
            depth--;
        }
    }
}