/*2022年12月26日23:03:25
贪心：种树*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a, vector<int> b);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int street_n, tips_n;
    cin >> street_n >> tips_n;
    int sum = 0;
    vector<vector<int>> tip(tips_n, vector<int>(3));//二维vector数组创建的方法
    for (int i = 0; i < tips_n; i++)
        cin >> tip[i][0] >> tip[i][1] >> tip[i][2];
    sort(tip.begin(), tip.end(), cmp);
    //首先先按这些刁民的要求按右边界排序
    //为了使得重叠区域利用率最高
    //添加树的规则为：从每个尾端开始添加树，直到该区间符合刁民要求
    //当然会先扫描一遍，如果已经符合要求了就啥也不做
    bool street[street_n + 1];
    for (int i = 1; i <= street_n; i++)
        street[i] = false;
    for (int i = 0; i < tips_n; i++)
    {
        int temp=0;
        for(int j=tip[i][0];j<=tip[i][1];j++)
        {
            if(street[j]) temp++;
        }
        if(temp>=tip[i][2])
        continue;
        else
        {
            int cou=0;
            for(int j=tip[i][1];j>=tip[i][0]&&cou<tip[i][2]-temp;j--)
            {
                if(!street[j])
                {
                    street[j]=true;
                    cou++;
                }
            }
        }
    }
    for(int i=1;i<=street_n;i++)
    sum+=street[i];
    cout << sum << endl;
}

bool cmp(vector<int> a, vector<int> b)
{
    return a[1] <= b[1];//二维vector数组比较函数的写法
}