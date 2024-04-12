/*2022年11月23日13:29:14
ios::sync_with_stdio（false）和cin.tie(0)*/
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);//关闭同步,这之后c++流不与c流同步，不能同时使用cout和printf，但可以同时使用cout和scanf
    //如果在标准流的I/O发生后调用这个函数，其行为是由实现定义的：实现范围从没有影响到破坏读缓冲区。
    cin.tie(0);//将cin与cout解开——默认情况下，每次从cin读取内容时， cout缓冲区都会刷新,解除后，可能cout不会自动输出
    //对于大数据的题目，在输入前没有要输出的，加这一行一点问题没有
    int nums;
    cin>>nums;
    int a;
    scanf("%d",&a);
    //如果输入：1 2 3
    //这是c++流，c流中仍然是啥也没有，因此你必须再输入一个数字，scnaf才能够读到数据
    //即输入1 2
    //1
    //最后nums=1，a=1
    while(nums--)
    {
        
    }
    return 0;
}