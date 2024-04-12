/*2023年2月3日11:45:50
Treap（树堆）这种数据结构同时具备二叉查找树和堆的性质，利用堆的性质使得这棵二叉查找树有着近似平衡二叉查找树的性质
Treap 每个结点记录两个数据，一个是键值，一个是随机附加的优先级。
Treap 在以关键码构成二叉排序树的同时，又以结点优先级形成最//大堆和最小堆
这里给出的是旋转实现*/
//TODO: 2023年2月3日11:45:50
#ifndef Treap_H_
#define Treap_H_
#define ElementType int
#include <stdlib.h>
#include <iostream>

struct Treap_TreeNode;
typedef struct Treap_TreeNode* Position;
typedef struct Treap_TreeNode* Treap;

void Insert(ElementType X,Treap& T);//插入
void Delete(ElementType X,Treap& T);//删除
static Position SingleRotateWithLeft(Position K2);//左旋转
static Position SingleRotateWithRight(Position K2);//右旋转
int query_rank(ElementType X,Treap T);//查询该树中X这个值的大小排名
ElementType query_val(int rank,Treap T);//查询该树中第rank大的节点的值
int query_prev(Treap T, ElementType X);//查询第一个比 X 小的节点
int query_nex(Treap T, ElementType X);//查询第一个比 X 大的节点

#endif