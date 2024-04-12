/*2023年1月7日11:57:14
深度优先搜索*/
//指路：洛谷P2404：自然数的拆分问题
//指路：洛谷P1706：全排列问题
//指路：洛谷P1219：八皇后 Checker Challenge
#include <iostream>
#include <windows.h>

int main (void)
{
    system("pause");
    return 0;
}

//关键：解决“当下该如何做”，至于“下一步如何做”是和“当下该如何做”是一样的
//实际上是一条路走到黑，再回溯回去尝试别的可能
//实际上是利用了栈这个数据结构，LIFO
//基本模型：
/*
void dfs(int step)
{
    判断边界(可能有关于step)
    尝试每一种可能for(int i=1;i<=n;i++)
    {
        继续下一步dfs(step+1);
    }
    返回
}
*/