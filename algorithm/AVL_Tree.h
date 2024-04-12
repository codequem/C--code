/*2023年1月25日20:46:23
AVL树（带有平衡条件的二叉查找树）的实现*/
#ifndef AVL_Tree_H_
#define AVL_Tree_H_
struct AVL_TreeNode;
typedef struct AVL_TreeNode* Position;
typedef struct AVL_TreeNode* AVL_Tree;

AVL_Tree MakeEmpty(AVL_Tree T);
Position Find(int X,AVL_Tree T);
Position FindMin(AVL_Tree T);
Position FindMax(AVL_Tree T);
AVL_Tree Insert(int X,AVL_Tree T);
AVL_Tree Delete(int X,AVL_Tree T);
int Retrieve(Position P);

#endif