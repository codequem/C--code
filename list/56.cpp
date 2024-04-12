//--------------------用邻接表实现无向图的深度优先遍历和广度优先遍历算法------------------------------------
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <list>
#include <queue>
#include <windows.h>

#define MAX_VEXTEX_NUM 20

using namespace std;
//改成自己的名字和学号
string name = "程一帆";
string id = "E22214111";

bool visited[MAX_VEXTEX_NUM]; //用于标记顶点是否被访问过

//定义边的数据类型
typedef struct ArcNode
{
    int adjvex;              //结点元素值
    struct ArcNode *nextarc; //指向下一条边的指针
} ArcNode;
//定义顶点的数据类型
typedef struct VNode
{
    int data;          //顶点的标号
    ArcNode *firstarc; //指向第一条依附该顶点的边的指针
} Vnode, AdjList[MAX_VEXTEX_NUM];

typedef struct
{
    AdjList vertices;   //邻接表
    int vexnum, arcnum; //图的当前顶点数和弧数
} ALGraph;

//以下可以根据需要定义自己的函数

//该函数查找顶点x在图的邻接表中的位置,如果找到返回该顶点在邻接表中的位置，否则返回-1
int LocateVex(ALGraph G, int x)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == x)
            return i;
    }
    return -1;
}

//该函数向图中添加一条边<x,y>
void AddEdge(ALGraph &G, int x, int y)
{
    int i, j;
    ArcNode *p, *q;
    i = LocateVex(G, x);
    j = LocateVex(G, y);
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = j;
    p->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = p;
    q = (ArcNode *)malloc(sizeof(ArcNode));
    q->adjvex = i;
    q->nextarc = G.vertices[j].firstarc;
    G.vertices[j].firstarc = q;
}

//该函数从图中删除一条边<x,y>
void DeleteEdge(ALGraph &G, int x, int y)
{
    int i, j;
    ArcNode *p, *q;
    i = LocateVex(G, x);
    j = LocateVex(G, y);
    p = G.vertices[i].firstarc;
    if (p->adjvex == j)
    {
        G.vertices[i].firstarc = p->nextarc;
        free(p);
    }
    else
    {
        while (p->nextarc->adjvex != j)
            p = p->nextarc;
        q = p->nextarc;
        p->nextarc = q->nextarc;
        free(q);
    }
    p = G.vertices[j].firstarc;
    if (p->adjvex == i)
    {
        G.vertices[j].firstarc = p->nextarc;
        free(p);
    }
    else
    {
        while (p->nextarc->adjvex != i)
            p = p->nextarc;
        q = p->nextarc;
        p->nextarc = q->nextarc;
        free(q);
    }
}

//该函数创建一个图
void CreateGraph(ALGraph &G)
{
    int i, j, k;
    int x, y;
    cout << "请输入图的顶点数和边数：";
    cin >> G.vexnum >> G.arcnum;
    cout << "请输入图的顶点：";
    for (i = 0; i < G.vexnum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    cout << "请输入图的边：";
    for (k = 0; k < G.arcnum; k++)
    {
        cin >> x >> y;
        i = LocateVex(G, x);
        j = LocateVex(G, y);
        AddEdge(G, x, y);
    }
}

//该函数销毁一个图
void DestroyGraph(ALGraph &G)
{
    int i;
    ArcNode *p, *q;
    for (i = 0; i < G.vexnum; i++)
    {
        p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            q = p;
            p = p->nextarc;
            free(q);
        }
    }
    G.vexnum = 0;
    G.arcnum = 0;
}

//该函数输出图的邻接表
void DisplayGraph(ALGraph G)
{
    int i;
    ArcNode *p;
    cout << "图的邻接表为：" << endl;
    for (i = 0; i < G.vexnum; i++)
    {
        cout << G.vertices[i].data << "->";
        p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            cout << G.vertices[p->adjvex].data << "->";
            p = p->nextarc;
        }
        cout << "NULL" << endl;
    }
}

//该函数输出图的深度优先搜索序列
void DFS(ALGraph G, int v)
{
    int i;
    ArcNode *p;
    cout << 'v' << G.vertices[v].data;
    visited[v] = true;
    p = G.vertices[v].firstarc;
    while (p != NULL)
    {
        i = p->adjvex;
        if (visited[i] == false)
        {
            cout<<"->";
            DFS(G, i);
        }
        p = p->nextarc;
    }
}

//该函数输出图的广度优先搜索序列
void BFS(ALGraph G, int v)
{
    int i;
    ArcNode *p;
    int queue[MAX_VEXTEX_NUM];
    int front, rear;
    front = rear = 0;
    cout << 'v' << G.vertices[v].data << "->";
    visited[v] = true;
    queue[rear++] = v;
    while (front != rear)
    {
        i = queue[front++];
        p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            if (visited[p->adjvex] == false)
            {
                cout<< 'v' << G.vertices[p->adjvex].data << "->";
                visited[p->adjvex] = 1;
                queue[rear++] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
}

//主函数
int main(int argc, char *argv[])
{
    //输出你的姓名和学号
    cout << name << endl<< id << endl;

    ALGraph G;
    //请补充你的代码：请按照图7.13（a）（参考书pg. 168 图 G4）初始化图G
    CreateGraph(G);
    //请补充你的代码：调用图的深度优先搜索策略（请参考书pg.169）访问图G，并且在屏幕上输出G的深度优先访问序列：v1->v2->v4->v8->v5->v3->v6->v7
    DFS(G, 0);
    memset(visited, false, sizeof(visited));
    cout<<endl;
    //请补充你的代码：调用图的广度优先搜索策略（请参考书pg.170）访问图G，并且在屏幕上输出G的广度优先访问序列：v1->v2->v3->v4->v5->v6->v7->v8
    BFS(G, 0);
    memset(visited, false, sizeof(visited));
    cout<<endl;
    //请补充你的代码: 销毁 G
    DestroyGraph(G);

    system("pause");
    return 1;
}
