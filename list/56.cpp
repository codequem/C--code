//--------------------���ڽӱ�ʵ������ͼ��������ȱ����͹�����ȱ����㷨------------------------------------
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <list>
#include <queue>
#include <windows.h>

#define MAX_VEXTEX_NUM 20

using namespace std;
//�ĳ��Լ������ֺ�ѧ��
string name = "��һ��";
string id = "E22214111";

bool visited[MAX_VEXTEX_NUM]; //���ڱ�Ƕ����Ƿ񱻷��ʹ�

//����ߵ���������
typedef struct ArcNode
{
    int adjvex;              //���Ԫ��ֵ
    struct ArcNode *nextarc; //ָ����һ���ߵ�ָ��
} ArcNode;
//���嶥�����������
typedef struct VNode
{
    int data;          //����ı��
    ArcNode *firstarc; //ָ���һ�������ö���ıߵ�ָ��
} Vnode, AdjList[MAX_VEXTEX_NUM];

typedef struct
{
    AdjList vertices;   //�ڽӱ�
    int vexnum, arcnum; //ͼ�ĵ�ǰ�������ͻ���
} ALGraph;

//���¿��Ը�����Ҫ�����Լ��ĺ���

//�ú������Ҷ���x��ͼ���ڽӱ��е�λ��,����ҵ����ظö������ڽӱ��е�λ�ã����򷵻�-1
int LocateVex(ALGraph G, int x)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == x)
            return i;
    }
    return -1;
}

//�ú�����ͼ�����һ����<x,y>
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

//�ú�����ͼ��ɾ��һ����<x,y>
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

//�ú�������һ��ͼ
void CreateGraph(ALGraph &G)
{
    int i, j, k;
    int x, y;
    cout << "������ͼ�Ķ������ͱ�����";
    cin >> G.vexnum >> G.arcnum;
    cout << "������ͼ�Ķ��㣺";
    for (i = 0; i < G.vexnum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    cout << "������ͼ�ıߣ�";
    for (k = 0; k < G.arcnum; k++)
    {
        cin >> x >> y;
        i = LocateVex(G, x);
        j = LocateVex(G, y);
        AddEdge(G, x, y);
    }
}

//�ú�������һ��ͼ
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

//�ú������ͼ���ڽӱ�
void DisplayGraph(ALGraph G)
{
    int i;
    ArcNode *p;
    cout << "ͼ���ڽӱ�Ϊ��" << endl;
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

//�ú������ͼ�����������������
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

//�ú������ͼ�Ĺ��������������
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

//������
int main(int argc, char *argv[])
{
    //������������ѧ��
    cout << name << endl<< id << endl;

    ALGraph G;
    //�벹����Ĵ��룺�밴��ͼ7.13��a�����ο���pg. 168 ͼ G4����ʼ��ͼG
    CreateGraph(G);
    //�벹����Ĵ��룺����ͼ����������������ԣ���ο���pg.169������ͼG����������Ļ�����G��������ȷ������У�v1->v2->v4->v8->v5->v3->v6->v7
    DFS(G, 0);
    memset(visited, false, sizeof(visited));
    cout<<endl;
    //�벹����Ĵ��룺����ͼ�Ĺ�������������ԣ���ο���pg.170������ͼG����������Ļ�����G�Ĺ�����ȷ������У�v1->v2->v3->v4->v5->v6->v7->v8
    BFS(G, 0);
    memset(visited, false, sizeof(visited));
    cout<<endl;
    //�벹����Ĵ���: ���� G
    DestroyGraph(G);

    system("pause");
    return 1;
}
