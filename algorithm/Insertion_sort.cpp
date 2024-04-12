/*2022年12月23日17:01:02
插入排序*/
#include <iostream>

using std::cout;

template <typename T>
T *insertion_sort(T *, int);
template <typename T>
void swap(T &, T &);

int main(void)
{
    int array[10] = {1, 4, 5, 3, 8, 7, 9, 6, 4, 2};
    int *p = insertion_sort(array, 10);
    for (int i = 0; i < 10; i++)
        cout << *(p + i) << ' ';
    return 0;
}

template <typename T>
T *insertion_sort(T *p, int n)
{ //这里按从小到大排序
    for(int i=1;i<n;i++)//这里的i是新摸上来的一张牌
    {
        int j=i-1;//这里的j是目前为止已经排好顺序的数组下标
        while(*(p+j)>*(p+j+1)&&j>=0)//不符合排序规则就一直向前交换直到这i张牌都有序
        {
            swap(*(p+j),*(p+j+1));
            --j;
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