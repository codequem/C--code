#include <iostream>
using namespace std;
int dfs(int *arr, int len, int tar, int now, int step, int c);
int main()
{
    int N[30];
    int n, m;
    cin >> n >> m;
    m*=2;
    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
        N[i]*=2;
    }
    cout << dfs(N, n, m, 0, 0, 0);
    return 0;
}

int dfs(int *arr, int len, int tar, int now, int step, int c)
{
    if (now == tar)
        return c;
    if (step >= len)
        return -1;
    dfs(arr, len, tar, now + arr[step], step+1, c);
    dfs(arr, len, tar, now + arr[step] / 2, step+1, c + 1);
    dfs(arr, len, tar, now, step+1, c);
    return -1;
}