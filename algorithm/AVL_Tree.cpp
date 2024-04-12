/*2023年1月22日23:02:35
二叉查找树的实现*/
//在vs上测试过了，能跑
#include <iostream>
#include "AVL_Tree.h"

struct AVL_TreeNode
{
    int Element;
    AVL_Tree Left;
    AVL_Tree Right;
    int subTreeNode;
    int samevalue=0;
    int Height;
}

static int
Height(Position P)
{
    if (P == NULL)
        return -1;
    else
        return P->Height;
}

AVL_Tree Insert(int X, AVL_Tree T)
{
    if (T == NULL)
    {
        T = (AVL_Tree)malloc(sizeof(struct AVL_TreeNode));
        if (T == NULL)
            std::cerr << "out of space!";
        else
        {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
    {
        T->Left = Insert(X, T->Left);
        T->subTreeNode++;
        if (Height(T->Left) - Height(T->Right) == 2)
        {
            if (X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if (X > T->Element)
    {
        T->Right = Insert(X, T->Right);
        T->subTreeNode++;
        if (Heiget(T->Right) - Height(T->Left) == 2)
        {
            if (X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    else
        T->samevalue++;
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

int getSubTreeSize(AVLTree Tree) {
	int cnt = 0;
	if (Tree->left)
		cnt = Tree->left->subTreeSize + 1;
	else cnt = 1;
	if (Tree->right)
		cnt += Tree->right->subTreeSize;
	return cnt;
}

int findKth(AVLTree Tree, int k) {//寻找第k小的数
	if (k > Tree->subTreeSize)return -1;
	if (!Tree->left && !Tree->right)return Tree->value;
	if (Tree->left) {
		int now = Tree->left->subTreeSize + 1;
		if (now == k)return Tree->value;
		else if (now > k)
			return findKth(Tree->left, k);
		if (Tree->right)
			return findKth(Tree->right, k - now);
	}
	else {
		if (k == 1)
			return Tree->value;
		else
			return findKth(Tree->right, k - 1);
	}
}

static Position SingleRotateWithLeft(Position K2)//K2是从叶到根的路径上第一次出现破坏AVL树规则的地方
{
    Position K1;//先给定一个位置来做K2左子树，以便我们来进行操作（ 为什么不直接用K2->Left？
    //因为我们还得保证）
    K1 = K2->Left;//让这个临时节点来做K2左子树的根
    //以下的细节看图，还有:双旋转就是两次单旋转的结合，因此直接调用两次单旋转即可
    K2->Left = K1->Right;    //K2，K1是节点                    /*               K2                   K1 */
    K1->Right = K2;                                          /*              /   \                 /  \  */
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;/*           K1     Z(子树)  =>     X    K2 */
    K1->Height = Max(Height(K1->Left), Height(K2->Height)) + 1;/*         /  \                       /  \  */
    return K1;//新树的根                                      /*       X(子树) Y(子树)               Y    Z */
}

static Position DoubleRotateWithLeft(Position K3)
{
    K3->Left=SingleRotateWithRight(K3->Left);//注意：双旋转实际上就是两次单旋转操作
    return SingleRotateWithLeft(K3);
}

static Position SingleRotateWithRight(Position K2)
{
    Position K1;
    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Right), Height(K2->Height)) + 1;
    return K1;
}

static Position DoubleRotateWithRight(Position K3)
{
    K3->Right=SingleRotateWithLeft(K3->Right);
    return SingleRotateWithRight(K3);
}