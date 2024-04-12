/*2023年1月22日23:02:35
二叉查找树的实现*/
#ifndef Binary_Search_Tree_H_
#define Binary_Search_Tree_H_

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(int X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int X,SearchTree T);
SearchTree Delete(int X,SearchTree T);
int Retrieve(Position P);

#endif