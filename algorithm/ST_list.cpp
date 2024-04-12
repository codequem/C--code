/*2022年12月28日22:14:01
ST表（Sparse Table)稀疏表*/
#include <iostream>
#define N 100

using namespace std;

int f[N][32],lg[N];//这里ST表能存的数组长度最大为2^32-1
//设st[i][j]表示区间[i,i+2^j-1]内的最值，显然st[i……n][0]就是原数据
//这里lg数组是预处理，lg[i]=向下取整（log2 i：以二为底i的对数），为了便于应对给出的查询长度

void init(int n);
int query(int l,int r);

int main (void)
{
    const int n=10;
    for(int i=0;i<10;i++)
    cin>>f[i][0];//设st[i][j]表示区间[i,i+2^j-1]内的最值，显然st[i……n][0]就是原数据，将这些传递给st表
    init(n);//n就是数据个数
    for(int i=0;i<3;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<endl;//三次问询
    }
    return 0;
}

void init(int n)
{
    for(int i=2;i<=n;i++)
    lg[i]=lg[i-1]+!(i&(i-1));//这里i每次取到2的幂时lg[i]才会递增一
    //这里lg数组是预处理，lg[i]=向下取整（log2 i：以二为底i的对数），为了便于应对给出的查询长度
    //一直计算出区间间隔1~n（也就是所有可能的值）
    //计算结果为：lg[1]=0 lg[2]=1 lg[3]=1 lg[4]=2 lg[5]=2 lg[6]=2 lg[7]=2 lg[8]=3
    //当然如果真的想可以直接利用std::__lg()函数，这也是O(1)复杂度的，可以直接用，注意有两个下划线
    for(int j=1;j<=lg[n];j++)//这里是枚举区间长度
        for(int i=1;i+(1<<j)-1<=n;i++)//这里是枚举起点
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    //对于st表的构建，区间[i,i+2^j-1]内的最值通过区间[i,i+2^(j-1)-1]，[i+2^(j-1),i+2^j-1]合并得到
}

int query(int l,int r)
{
    int k=lg[r-l+1];//借助提前算好的lg数组直接确定需要给到的小区间长度是多少
    return max(f[l][k],f[r-(1<<k)+1][k]);
}