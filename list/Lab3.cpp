#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 300
#define maxm 300

using namespace std;

int n, m;                   // n为进程的个数，m为资源类型的个数
int Available[maxm];        // 可利用资源向量
int Max[maxn][maxm];        // 最大需求矩阵
int Allocation[maxn][maxm]; // 分配矩阵
int Need[maxn][maxm];       // 需求矩阵
int Request[maxm], id;      // 请求向量
int ssj[maxn];              // n个进程完成情况
int work[maxm];             // 工作空间
int Queue[maxn], Qi;        // 存安全队列

const string Name = "E22214111 程一帆";

bool RN(int k)
{ // 第k个进程需求资源小于声明需求
    for (int i = 0; i < m; i++)
    {
        if (Request[i] > Need[k][i])
            return 0;
    }
    return 1;
}
bool RA(int k)
{ // 第k个进程需求资源小于可利用资源
    for (int i = 0; i < m; i++)
    {
        if (Request[i] > Available[i])
            return 0;
    }
    return 1;
}
void fenpei(int k)
{ // 分配资源
    for (int i = 0; i < m; i++)
    {
        Available[i] -= Request[i];
    }
    for (int i = 0; i < m; i++)
    {
        Allocation[k][i] += Request[i];
    }
    for (int i = 0; i < m; i++)
    {
        Need[k][i] -= Request[i];
    }
}

void chexiao(int k)
{
    for (int i = 0; i < m; i++)
    {
        Available[i] += Request[i];
    }
    for (int i = 0; i < m; i++)
    {
        Allocation[k][i] -= Request[i];
    }
    for (int i = 0; i < m; i++)
    {
        Need[k][i] += Request[i];
    }
}

void print()
{
    printf("--------------当前进程、资源情况--------------\n");
    printf("\t%10s%16s%10s\n", "Max", "allocation", "Need");
    printf("进程名\t");
    for (int x = 0; x < 3; x++)
    {
        printf("      ");
        for (int i = 0; i < m; i++)
            printf("%2c", 'a' + i);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("    %d   ", i);
        printf("      ");
        for (int j = 0; j < m; j++)
            printf("%2d", Max[i][j]);
        printf("      ");
        for (int j = 0; j < m; j++)
            printf("%2d", Allocation[i][j]);
        printf("      ");
        for (int j = 0; j < m; j++)
            printf("%2d", Need[i][j]);
        printf("\n");
    }
    printf("系统可利用资源：");
    for (int i = 0; i < m; i++)
        printf("%3d", Available[i]);
    printf("\n ---------------------------------------------\n");
}

bool issafe()
{ // 安全性算法
    memset(ssj, 0, sizeof(ssj));
    memcpy(work, Available, sizeof(int) * (m + 1));
    Qi = 0;
    for (int i = 0; i < n; i++)
    {
        if (ssj[i])
            continue;
        int j;
        for (j = 0; j < m; j++)
        {
            if (Need[i][j] > work[j])
                break;
        }
        if (j == m)
        {
            for (j = 0; j < m; j++)
            {
                work[j] += Allocation[i][j];
            }
            ssj[i] = 1;
            Queue[Qi++] = i;
            i = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!ssj[i])
            return 0;
    }
    return 1;
}

int Dijkstra()
{
    if (issafe() == 0)
    {
        printf("初始数据不安全\n");
        return 1;
    }
    while (1)
    {
        printf("\n请输入一个请求进程的id和请求进程各个资源的量：\n");
        scanf("%d", &id);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &Request[i]);
        }
        if (RN(id))
        {                // 判断小于声明的
            if (!RA(id)) // 大于系统资源
                printf("尚无足够资源，进程须等待\n");
            else
            {
                fenpei(id);
                if (issafe())
                { // 分配资源
                    printf("存在一个安全队列:");
                    for (int i = 0; i < Qi; i++)
                    {
                        if (i)
                            printf("->");
                        printf("%d", Queue[i]);
                    }
                    printf("\n分配成功！\n");
                    print();
                }
                else
                {
                    chexiao(id);
                    printf("不安全，不给分配！\n");
                }
            }
        }
        else
        {
            printf("出错，所需资源超过声明最大资源\n");
        }
    }
}

int main()
{
    cout << Name << endl;
    printf("请输入进程数和资源数：\n");
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%d", &Max[i][j]);
        for (int j = 0; j < m; j++)
            scanf("%d", &Allocation[i][j]);
        for (int j = 0; j < m; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];
    }
    printf("请输入系统可利用资源：\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &Available[i]);
    print();
    Dijkstra();
    return 0;
}