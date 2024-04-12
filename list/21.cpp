#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,L;
double lef=-1e6,rig=1e6,dlt=1e-5,pre[N],a[N],b[N]; //dlt:题目所要求的的精度 
void init()
{
	scanf("%d%d",&n,&L);
	for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
}
bool check(double m)
{
	double min_left=1e10,anss=-1e10; //min_left:最小前缀和 
	for (int i=1;i<=n;i++) b[i]=a[i]-m;
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+b[i];//pre[]:前缀和数组 
	for (int r=L;r<=n;r++) //一个小贪心，从L开始枚举右端点
	{
		min_left=min(min_left,pre[r-L]);//不断更新符合条件的最小前缀和
		if (pre[r]-min_left>=0) return true;
	} 
	return false;
}
double cut()
{
	while (rig-lef>dlt)
	{
		double mid=(lef+rig)/2;
		if (check(mid)==true) lef=mid; //check()：判断anss是否还能更大 
		else rig=mid; 
	}
	return rig; 
}
int main()
{
	init();
	cout<<(int)(cut()*1000)<<endl;
	return 0;
}
