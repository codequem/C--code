/*2022年12月23日17:52:07
希尔排序(改进了的插入排序)*/
#include <iostream>

using std::cout;

template <typename T>
void swap(T &, T &);
template <typename T>
T *shell_sort(T *, int);

int main(void)
{
    int array[10] = {1, 4, 5, 3, 8, 7, 9, 6, 4, 2};
    int *p = shell_sort(array, 10);
    for (int i = 0; i < 10; i++)
        cout << *(p + i) << ' ';
    return 0;
}

template <typename T>
T *shell_sort(T *p, int n)
{ //这里按从小到大排序
    int h=1;
    while(h<n/3)
    {
        h=3*h+1;//这里利用knuth序列来确定间隔
    }

    for(int gap=h;gap>0;gap=(gap-1)/3)//gap:间隔，不同于插入排序
    //希尔排序以更大的间隔进行插入排序，这样做有两个好处
    //在间隔很大时，需要进行的交换的次数是很少的
    //而在间隔变得很小时，因为先粗略的处理了一遍了，所以数组已经大致有序了，此时需要交换的距离就很短
    //正是这两个特点使的它的效率更高
    {
        for(int i=gap;i<n;i++)
        {
            int j=i-gap;
            while(*(p+j)>*(p+j+gap)&&j>=0)
            {
                swap(*(p+j),*(p+j+gap));
                j-=gap;
            }
        }
    }
    return p;
}

template <typename T>
void swap(T &x, T &y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;
}