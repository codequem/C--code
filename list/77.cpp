// 全排列
#include <bits/stdc++.h>

void dfs(int *arr, int length);
void bfs(int *arr, int length);
static queue<int> q;
static vector<vector<int>> result;
static bool use[5];

using namespace std;
int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    dfs(arr, 5);
    bfs(arr, 5);
    return 0;
}

void dfs(int arr, int length)
{
}

void bfs(int arr, int length)
{
    if(length<=0)
    for (int i = 0; i < length; i++)
    {
        if (!use[i]&&arr[i]!=q.top())
        {
            use[i] = true;
            q.push(arr[i]);
            bfs(arr,length-1);
        }
    }
}