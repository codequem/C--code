/*2022年12月27日23:03:51
前缀和与差分算法*/
#include <iostream>
#include <algorithm>

using namespace std;
void insert(int x1,int y1,int x2,int y2,int c,int (&d)[6][6]);

int main (void)
{
    //一维前缀和
    int arr[10]={2,5,1,3,77,1,2,23,12,23};
    long long sum[11]={0};//sum[i]保存着arr[1~i]之和//这里的i是第i个数，不是下标，如sum[10]是arr的前10个数之和
    //sum[0]是0
    for(int i=0;i<10;i++)
        sum[i+1]=sum[i]+arr[i];//求出给定数组的一维前缀和
    //之后要查询任意该数列中下标l~r的元素之和只需要返回sum[r+1]-sum[l],而不需要遍历，时间起飞
    //实例见luogu P3131

    //二维前缀和
    int matrix[5][5]={
        {1,2,3,4,5},
        {2,3,4,5,6},
        {3,4,5,6,7},
        {4,5,6,7,8},
        {5,6,7,8,9}
    };
    long long sum_matrix[6][6]={0};//sum_matrix[i][j]表示的是matrix[0][0]到matrix[i-1][j-1]区块的和值
    for(int i=1;i<6;i++)
        for(int j=1;j<6;j++)
        {
            sum_matrix[i][j]=sum_matrix[i-1][j]+sum_matrix[i][j-1]-sum_matrix[i-1][j-1]+matrix[i-1][j-1];
        }
    //经过计算sum_matrix呈现下列结果
    //   0   1   2   3   4   5
    //0  0   0   0   0   0   0 
    //1  0   1   3   6  10  15
    //2  0   3   8  15  24  35
    //3  0   6  15  27  42  60
    //4  0  10  24  42  64  90
    //5  0  15  35  60  90 125
    
    //那么要查询matrix（1,2）到（3,4）的加和为：
    int ans=sum_matrix[4][5]-sum_matrix[1][5]-sum_matrix[4][2]+sum_matrix[1][2];
    //以（x1,y1）为左上角，（x2,y2）为右下角的矩形面积为：
    //S=sum_matrix[x2+1][y2+1]-sum_matrix[x1][y2+1]-sum_matrix[x2+1][y2]+sum_matrix[x1][y1];
    //查询时间也起飞了

    //差分：可以理解为前缀和的逆运算
    //一维差分：
    //首先给定一个原数组a:a[1]~a[n]  构造一个数组b
    //使得a[i]=b[1]+……+b[i],也就是说a是b数组的前缀和数组，反过来我们说b数组是a数组的差分数组
    int a[11]={0,1,3,6,10,15,21,28,36,45,55};//注意a[0]=0,后面的（a[1]~a[10])才是a数组原本的内容
    int b[11]={0};
    for(int i=1;i<11;i++)
    b[i]=a[i]-a[i-1];//这样方法构造的b数组就达到了a[i]=b[1]+……+b[i]
    //b[1]~b[10]:1 2 3 4 5 6 7 8 9 10,作为a[1]~a[10]的差分数组，可以在O(n)时间内求出a数组
    //但是差分数组有什么用咧？
    //这里假设要求原数组中l~r区间上的每一个数都加上c，暴力做法是遍历O(n)
    //但是我们可以只修改差分数组从而达到O(1)的时间复杂度
    //打个比方，要求a[3]~a[7]的元素都加上5，那么只需要
    //更改b[3]变为b[3]+5，这一步让a[3]之后的所有元素都+5
    //更改b[8]变为b[8]-5，这一步让a[8]及之后的所有元素恢复正常
    //这就是一维差分结论

    //二维差分：同理我们想要被选中的子矩阵中的每个元素加上c，使用二维差分来达到O(1)的时间复杂度
    int c[5][5]={
        {1,3,6,10,15},
        {3,8,15,24,35},
        {6,15,27,42,60},
        {10,24,42,64,90},
        {15,35,60,90,125}
    };
    int d[6][6]={0};
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            insert(i,j,i,j,c[i][j],d);//这里是通过对差分数组进行插入修改操作来构建差分数组
            //这里利用插入操作构建的差分数组的下标范围为x(0~4),y(0~4)
            //当原数组和差分数组都是以下标1开始的时候，常规的构建公式如下
            //b[i][j] = a[i][j] − a[i − 1][j] − a[i][j − 1] + a[i −1 ][j − 1]
        }
    return 0;
}

void insert(int x1,int y1,int x2,int y2,int c,int (&d)[6][6])
{   //对d数组执行插入操作，等价于对c数组中的(x1,y1)到(x2,y2)之间的元素都加上了c
    d[x1][y1] += c;
    d[x2 + 1][y1] -= c;
    d[x1][y2 + 1] -= c;
    d[x2 + 1][y2 + 1] += c;
}