/*2023-1-5 10:02:54
啊哈，算法是本好书
快速排序*/
#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

template<typename T>
void quick_sort(T* arr,int n);
template<typename T>
void swap(T& a,T &b){
    T temp=a;
    a=b;
    b=temp;
};

int main (void)
{
    int array[15]={6,1,2,7,9,3,4,5,10,8,21,23,14,25,16};
    quick_sort(array,15);
    for(int i=0;i<15;i++)
    cout<<array[i]<<' ';
    system("pause");
    return 0;
}

template<typename T>
void quick_sort(T* arr,int n)
{
    if(n<=1)
    return;
    int i=0,j=n-1;
    while(i!=j)
    {
        for(;*(arr+j)>(*arr)&&(i!=j);j--);
        for(;*(arr+i)<=(*arr)&&(i!=j);i++);
        swap(*(arr+i),*(arr+j));
    }
    swap(*(arr+i),*(arr));
    quick_sort(arr,i);
    quick_sort(arr+i+1,n-i-1);
}

//快排的思想：对于一个数组，选定一个基准，使得比这个数小的全在一边，比这个数大的全在另一边
//如：6 1 2 7 9 3 4 5 10 8，选定6为基准
//算了基本思想见“啊哈，算法”