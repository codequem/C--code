/*2022年10月26日16:48:22
递归实现指数型枚举*/
/*从 1∼n 这 n 个整数中随机选取任意多个，输出所有可能的选择方案*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 16;

int n;
int st[N]; // 状态，记录每个位置当前的状态：0表示还没考虑，1表示选它，2表示不选它

void dfs(int u)
{
    if (u > n) // 每一种条件的终止限制条件
    {
        for (int i = 1; i <= n; i++)
            if (st[i] == 1)
                printf("%d ", i);
        printf("\n");
        return;
    }

    st[u] = 2;
    dfs(u + 1); // 第一个分支：不选
    st[u] = 0;  // 恢复现场

    st[u] = 1;
    dfs(u + 1); // 第二个分支：选
    st[u] = 0;
}

int main()
{
    cin >> n;

    dfs(1);

    return 0;
}
