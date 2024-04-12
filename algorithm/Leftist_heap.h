#ifndef Leftist_heap_H_
#define Leftist_heap_H_
#define ElementType int
#define Insert(X, H) (H = Insert1((X), H))

#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

struct TreeNode;
typedef struct TreeNode* PriorityQueue;

PriorityQueue Intialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2);
ElementType DeleteMin(PriorityQueue H);
ElementType IsEmpty(PriorityQueue H);
ElementType IsFull(PriorityQueue H);
PriorityQueue Insert1(ElementType X,PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);
#endif