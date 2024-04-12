#include <iostream>
#include <cmath>
#define maxn 120
int arr[maxn][maxn];
int tmp[maxn][maxn];
using namespace std;
int main(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 || j == 1 || i == n || j == m)
            {
                tmp[i][j] = arr[i][j];
                continue;
            }
            else
            {
                tmp[i][j] = round((1.0 * arr[i + 1][j] + arr[i][j + 1] + arr[i - 1][j] + arr[i][j - 1]+arr[i][j]) / 5.0);
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if(j==m)
            {
                cout<<tmp[i][j]<<endl;
                continue;
            } 
            cout<<tmp[i][j]<<' ';
        }
    int x;
    cin>>x;
    return 0;
}