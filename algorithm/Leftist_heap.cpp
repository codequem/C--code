#include "Leftist_heap.h"

struct TreeNode
{
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl; // NULL Path Length:零路径长，Npl（X）定义为从X到一个没有两个儿子的节点的最短路径的长
};

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
    if (H1 == NULL)
        return H2;
    if (H2 == NULL)
        return H1;
    if (H1->Element < H2->Element)
        return Merge1(H1, H2); //根据根的大小确定到底是谁并入谁
    else
        return Merge1(H2, H1);
}

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2) //静态函数只能在声明它的文件中可见
//其他文件不能使用该函数
{
    if (H1->Left == NULL)//只有一个节点，因为它是左式堆，左儿子都没，右儿子也是噶
        H1->Left = H2;//直接给他拉左边就行，这时候H2也就一个节点
    else
    {
        H1->Right=Merge(H1->Right,H2);//这里实际上是一直递归的，而且是两个函数互相递归
        if(H1->Left->Npl<H1->Right->Npl)//在merge函数中保证左右子树都不会空
            SwapChildren(H1);//调换左右树，使他又变成左式树，即，在递归过程后，只有根处会破坏左式堆的规则
        H1->Npl=H1->Right->Npl+1;
    }//递归程序永远斯巴拉西
    return H1;
}

static void SwapChildren(PriorityQueue H)
{
    struct TreeNode* temp=H->Left;//既然要交换，那左右子树都不会为空
    H->Left=H->Right;
    H->Right=temp;
}

PriorityQueue Insert1(ElementType X,PriorityQueue H)//插入不过是另一种形式的合并，直接用我们写好的合并函数即可
{
    PriorityQueue SingleNode;
    SingleNode = (PriorityQueue)malloc(sizeof(struct TreeNode));
    if(SingleNode==NULL)
    cout<<"out of space!!"<<endl;
    else
    {
        SingleNode->Element=X;
        SingleNode->Npl=0;
        SingleNode->Left=SingleNode->Right=NULL;
        H=Merge(SingleNode,H);
    }
    return H;
}

PriorityQueue DeleteMin1(PriorityQueue H)
{
    PriorityQueue LeftHeap,RightHeap;
    if(IsEmpty(H))
    {
        cout<<"PriorityQueue is Empty!"<<endl;
        return H;
    }
    LeftHeap=H->Left;
    RightHeap=H->Right;
    free(H);//出队的原理是，先把根删了，然后再把它的两个后裔合并,可以加一条输出语句以便知道出去的是啥
    return Merge(LeftHeap,RightHeap);
}

ElementType FindMin(PriorityQueue H)
{
    return H->Element;
}

ElementType DeleteMin(PriorityQueue H)
{
    ElementType temp=FindMin(H);
    H=DeleteMin1(H);
    return temp;//这里自动返回出队的值，指针也预先指好
}