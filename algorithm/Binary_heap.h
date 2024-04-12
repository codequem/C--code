/*2023年1月31日12:53:19
二叉堆的实现，并利用二叉堆来实现优先队列*/
//但是显然，二叉堆是不支持高效的合并操作的，让我们来try try左式堆
#ifndef _Binary_heap_H
#define _Binary_heap_H
#define ElementType int

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

struct Heap;
typedef struct Heap* PriorityQueue;
struct Heap
{
    int Capacity;
    int Size;
    int* Elements; //由于二叉堆完美的结构性，我们可以直接用一个数组来表示而不需要指针
};

PriorityQueue Initialize(ElementType MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H); //递归的删就行，因为是完全二叉树，高度不会太高，递归性能不会太差
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
bool IsEmpty(PriorityQueue H);
bool IsFull(PriorityQueue H);

#endif