/*2023年1月22日23:02:35
二叉查找树的实现*/
#include "Binary_Search_Tree.h"
#include <iostream>

/* typedef struct TreeNode* PtrToNode;
typedef struct TreeNode{
    int Element;
    PtrToNode FirstChild;//指向这个节点的第一个儿子
    PtrToNode NextSiBling;//指向这个节点的下一个兄弟
    //以上两个指针都有可能是空指针
}TreeNode;
//上面是普通的树的表示方法，树的任意节点最多只有一个“第一个儿子”和“下一个兄弟” 把无限的问题转化为有限的，相同的问题了*/

/* typedef struct TreeNode* PtrToNode;
typedef struct TreeNode{
    int Element;
    PtrToNode Left;//指向左节点(实际上是左子树)
    PtrToNode Right;//指向右节点(实际上是右子树)
    //以上两个指针都有可能是空指针
}TreeNode;
//这是二叉树的表示方法，因为每个节点最多只有两个儿子，所以咱可以直接用两个指针直接指向他们*/
//要使二叉树变成二叉查找树的性质是：对于树中的每个节点X。它的左子树中的所有节点中的关键字值都小于X的关键字值，而右子树都大于
//实际上二叉树也有着数组描述，但是我觉得没啥用捏，评价为：不如链表直观

typedef struct TreeNode
{
    int Element;
    SearchTree Left;
    SearchTree Right;
} TreeNode;

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(int X, SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (X < T->Element) //左子树都小于该节点
        return Find(X, T->Left);
    else if (X > T->Element) //右子树都大于该节点
        return Find(X, T->Right);
    else
        return T; //就是这个值，就返回它
}

Position FindMin(SearchTree T)
{
    //递归定义查找最小关键字值，等会查找最大的时候用非递归定义
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL) //总之就是一直找它的左子树（如果存在的话）
        return T;
    else
        return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;
    return T;
}

SearchTree Insert(int X, SearchTree T)
{
    if (T == NULL)
    {
        T = (SearchTree)malloc(sizeof(TreeNode)); //空树根的话就给它分配内存
        if (T == NULL)
            std::cout << "out of space!!" << std::endl; //分配了还是空，那就是内存满了
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
        T->Left = Insert(X, T->Left); //这里用递归，因为它应该在左子树，那就把他插入到左子树中啰
    else if (X > T->Element)
        T->Right = Insert(X, T->Right);
    //还有一种情况是X已经在树中了，那咱就什么也不干(如果)
    return T; //返回树根的位置，也是递归结束的点
}

//删除的程序就难了，显然有三种情况，第一种，我们要删除的节点是个树叶，第二种，它有一个儿子，第三种，它有两个儿子
SearchTree Delete(int X, SearchTree T)
{
    Position posi = Find(X, T); //存储将要删除的关键字的位置
    if (posi == NULL)
        std::cout << "Element not found" << std::endl;
    if (posi->Left && posi->Right) //左右同时为真，也就是有两个儿子
    {
        Position temp=FindMin(T->Right);//用它的右子树中的最小值(一定是一片叶子)代替它
        //因为这个值一定大于它的左子树而小于它的右子树
        posi->Element=temp->Element;//覆盖这个位置
        Delete(temp->Element,posi->Right);//这个最小值的位置只有可能有一个或零个儿子，递归的去删它
    }
    else //一个或者没有儿子
    {
        Position temp = posi;
        if (temp->Left)
            posi=posi->Left;//让它的儿子他带它的位置，也就是把他删了
        if (temp->Right)
            posi=posi->Right;
        free(temp);
    }
    return T;
}