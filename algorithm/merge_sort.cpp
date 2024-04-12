/*2022年12月24日12:22:25
归并排序*/

#include <iostream>
#define N 100000
using std::cout;
using std::cin;
int t[N];

template <typename T>
void merge_sort(T s,int e);

int main(void)
{
    int array[10] = {1, 4, 5, 3, 8, 7, 9, 6, 4, 2};
    merge_sort(array, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << array[i] << ' ';
    return 0;
}

template <typename T>
void merge_sort(T q[], int s,int e)
{
    if(e<=s) return;
    int mid=(e+s)>>1;
    merge_sort(q,s,mid),merge_sort(q,mid+1,e);//咱先给他分成一小块一小块
    
    int k=0,i=s,j=mid+1;//下面就是合并的程序了
    while(i<=mid&&j<=e)
    {
        if(q[i]<=q[j])
        t[k++]=q[i++];
        else
        t[k++]=q[j++];
    }
    while(i<=mid)
    t[k++]=q[i++];
    while(j<=e)
    t[k++]=q[j++];
    for(int i=s,j=0;i<=e;i++,j++)
    q[i]=t[j];
}