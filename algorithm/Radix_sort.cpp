/*2023年1月14日18:33:12
基数排序
https://www.runoob.com/w3cnote/radix-sort.html#:~:text=%E5%9F%BA%E6%95%B0%E6%8E%92%E5%BA%8F%E6%98%AF%E4%B8%80%E7%A7%8D%E9%9D%9E,%E4%B8%AA%E4%BD%8D%E6%95%B0%E5%88%86%E5%88%AB%E6%AF%94%E8%BE%83%E3%80%82*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <Windows.h>

using namespace std;

void radix_sort(int *p,int n);
int max_bit(int *p,int n);
int get_bit(int m,int k);

int main (void)
{
    int arr[10]={12,12342431,511,6,3234,9,723,0,4,8};
    radix_sort(arr,10);
    for(int i=0;i<10;i++)
    cout<<arr[i]<<' ';
    system("pause");
    return 0;
}

void radix_sort(int *p,int n)
{
    queue<int> bucket[10];//tmd桶应该用队列模拟，md一开始还以为是栈，我是傻鸟
    int maxbit=max_bit(p,n);//获取一共需要进行几次排序
    for(int i=1;i<=maxbit;i++)
    {
        for(int j=0;j<n;j++)
        {
            int book=get_bit(p[j],i);
            bucket[book].push(p[j]);//将数据压入对应的桶中
        }
        int k=0;
        for(int j=0;j<n;j++)
        {
            if(!bucket[k].empty())
            {
                p[j]=bucket[k].front();
                bucket[k].pop();//完成一次桶排序就让大家从队列中出来
                continue;
            }
            k++;
            j--;
        }
    }
}

max_bit(int *p,int n)
{
    int book=p[0];
    for(int i=0;i<n;i++)
    book=max(book,p[i]);
    int maxbit=0;
    while(book>0)
    {
        book/=10;
        maxbit++;
    }
    return maxbit;
}

int get_bit(int m,int k)
{
    for(int i=1;i<k;i++)
        m/=10;
    return m%10;
}