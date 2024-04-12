/*2022年12月25日21:57:57
二分*/
#include <iostream>
#include <cstdio>
#define N 10
#define eps 1e-8

using namespace std;

//关键问题在于二分边界的控制
//先注意一个问题：在mid=(l+r)/2中，中点是左偏的（偏小）//mid=l+(r-l)/2
//在mid=(l+r+1)/2中，中点是右偏的（偏大）//mid=l+(r-l+1)/2
int main (void)
{
    int arr[N]={1,3,4,4,4,4,7,7,8,10};
    const int target=4;
    //问题一：查找key=4的最小下标
    //问题二：查找第一个key>=4的下标
    //问题三：查找第一个key>4的下标
    //问题四：统计key=4的个数

    //先来解决问题一：
    int l=0,r=N-1;
    int ans=-1;//暂时存放已经确定的答案
    while(l<=r)//在这个方法里无论如何l,r每次都会改变，不会陷入死循环
    //终止条件为l>r
    {
        int mid=l+(r-l)/2;//防止加法导致溢出
        if(arr[mid]==target) 
        {
            ans=mid;//先把这个答案存下来
            r=mid-1;//因为要查找最小的，所以边界向右移动看看有没有更小的解
        }
        if(arr[mid]<target) l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<endl;

    //再来解决第二个问题,同上，只是改变    ==    ->   >=
    l=0,r=N-1,ans=-1;
    while(l<=r)//在这个方法里无论如何l,r每次都会改变，不会陷入死循环
    //终止条件为l>r
    {
        int mid=l+(r-l)/2;//防止加法导致溢出
        if(arr[mid]>=target) 
        {
            ans=mid;//先把这个答案存下来
            r=mid-1;//因为要查找最小的，所以边界向右移动看看有没有更小的解
        }
        else l=mid+1;
    }
    cout<<ans<<endl;

    //再来解决第三个问题,同上，只是改变    >=    ->   >
    l=0,r=N-1;
    int anss=-1;
    while(l<=r)//在这个方法里无论如何l,r每次都会改变，不会陷入死循环
    //终止条件为l>r
    {
        int mid=l+(r-l)/2;//防止加法导致溢出
        if(arr[mid]>target) 
        {
            anss=mid;//先把这个答案存下来
            r=mid-1;//因为要查找最小的，所以边界向右移动看看有没有更小的解
        }
        else l=mid+1;
    }
    cout<<anss<<endl;

    //这次来解决第四个问题
    if(ans==-1)
    {
       cout<<0<<endl;//一个都没找到就是0
    }
    if(ans!=-1&&anss==-1)
    {
        cout<<N-ans<<endl;//比它大的没了就拿数组长度来减
    }
    if(ans!=-1&&anss!=-1)
    {
        cout<<anss-ans<<endl;//如果都存在，相减就是答案
    }


    //以下是浮点二分
    //给定一个浮点数n，求它的三次方根,结果保留6位小数。
    //数据范围：−10000≤n≤10000

    //以下是代码实现
    double dl=-1e4,dr=1e4;
    double n;
    cin>>n;
    while(dr-dl>eps)//这里因为是浮点二分，所以用eps控制精度
    //一般来说，题目要求6位小数就设置为1e-8，4位小数就设置为1e-6
    {
        double dmid=(dl+dr)/2;
        if(dmid*dmid*dmid>=n) dr=dmid;//浮点数就直接取中点值
        else dl=dmid;//浮点数就直接取中点值
    }
    printf("%.6lf",dl);
}