/*2023年1月31日12:53:19
二叉堆的实现，并利用二叉堆来实现优先队列*/
//换句话说，我们可以用stl里的priority_queue来当二叉堆
#include "Binary_heap.h"
const int mindata = -32567;


//二叉堆是一颗被完全填满的二叉树，允许的例外是在堆的最底层，同时这样的树也被称为完全二叉树
//以下是堆用数组维护的原理：
//对于数组中任意位置i上的元素（这里的i从1开始，下标为0的地方被预留出来存放预期的最小值（堆中的数据不可越过这个值）
//其左儿子位于下标2i处，其右儿子位于2i+1处
/*
    O(预留)  A      B       C        D                         A
    0       1      2       3        4          =>            /  \
                                                           B     C
                                                         /
                                                        D
*/
//此外堆还要满足堆序性质，堆序性质简单来说就是根对它的所有节点都满足某个规则，比如说：
//小根堆:根的值小于它的所有后裔，注意，对于子树来说，它们同样可以看成一个新的堆，也要递归的满足该条件

PriorityQueue Initialize(ElementType MaxElements)
{
    PriorityQueue H;
    if (MaxElements < 1)
        cout << "Priority queue size is too small" << endl;
    H = (PriorityQueue)malloc(sizeof(struct Heap)); //先来给这个结构体分配空间
    if (H == NULL)
        cout << "out if space!!!" << endl;
    //现在我们来给堆中的元素分配内存
    H->Elements = (int*)malloc((MaxElements + 1) * sizeof(int));
    if (H->Elements == NULL)
        cout << "out of space!!!" << endl;
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = mindata; //确保这个堆中的元素无论如何也不会小过这个值，其目的是为了简化插入操作所需的时间
    //这个值我们称作标记
    return H;
}

//下面编写插入操作和优先队列的出队操作（即踢出最小值，这里默认优先规则为小的更优先）
//实际上，由于堆序性质，这两个操作都很简单，只需要始终保持堆序性质即可

void Insert(ElementType X, PriorityQueue H) //入队
{
    //注意这个函数不返回新的根的位置，因为根本上谁是根是priorityqueue的成员中的数组决定的
    //所以数组下标1处的元素就是根，不必返回位置
    int i;
    if (IsFull(H))
    {
        cout << "Priority is full!" << endl;
        return;
    }
    //这里i=++H->Size是因为我们还预留了下标为0的位置,第二个判断语句是确定是否插入成功的，i/2即在堆中的上一层尝试是否能插入
    for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
    {
        H->Elements[i] = H->Elements[i / 2]; //这里一开始时下标i处是空的,每一次循环都是让当前的根下降一级
        //同时这个空位上升一级，直到让这个X来填这个空不会破坏堆序性为止，这种一般的策略称为上滤
        //应该注意到，如果我们插入的这个值是新的根，i将会一直到1，此时，我们预留的下标为0的绝对不会被越过的最小值就能
        //让程序跳出这个循环，省的进行判断操作
    }
    H->Elements[i] = X; //把X放到它应该在的位置
}

ElementType DeleteMin(PriorityQueue H) //出队，注意也要维护堆的堆序性
{
    int i, child;
    ElementType MinElement, LastElement;
    if (IsEmpty(H))
    {
        cout << "Priority queue is empty!" << endl;
        return -1;
    }
    MinElement = H->Elements[1];//这就是我们要出队的家伙
    LastElement = H->Elements[H->Size--];//从堆的最下面拿一个出来等着
    for (i = 1; i * 2 <= H->Size; i = child)
    {
        //找这个根的最小的儿子，它将填补上被删去的根的位置
        child = i * 2;//乘二就是左子树
        //这个前半部分是为了防止这个堆的大小是偶数（也就是防止有的节点没有右儿子），起短路作用
        if (child != H->Size && H->Elements[child + 1] < H->Elements[child])
            child++;//右子树更小的话，+1就变成右子树了
        if (LastElement > H->Elements[child])
            H->Elements[i] = H->Elements[child];//这里是让根节点向上一级，空位向下一级，直到让
        //LastElement填进去不会破坏堆的堆序性为止，这种一般的策略称作下滤
        else break;//这是达到不破坏堆的堆序性的时机了，退出循环
    }
    H->Elements[i] = LastElement;
    return MinElement;//返回被出队的值
}

bool IsEmpty(PriorityQueue H)
{
    return H->Size == 0;
}

bool IsFull(PriorityQueue H)
{
    return H->Size == H->Capacity;
}
