#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <string>

#define MaxCount 100

using namespace std;

int c;                   //背包的容量
int d;                   //背包的容积
int n;                   //物品的数目
int w[MaxCount];         //存放重量
int b[MaxCount];         //存放体积
int v[MaxCount];         //存放价值
int result;              //最终计算出来的最大价值,实际上结果就是f[c][n][d]
bool ischoose[MaxCount]; //标记是否选中了，便于我们查看结果是否正确

void solve(void);

void read() //文件读
{
    ifstream ifs;
    ifs.open("C:\\Users\\cyf\\Desktop\\in.txt", ios::in);
    ifs >> n >> c >> d;
    for (int i = 1; i <= n; i++)
    {
        ifs >> w[i] >> b[i] >> v[i];
    }
    ifs.close();
}

void write() //文件写
{
    ofstream ofs;
    ofs.open("C:\\Users\\cyf\\Desktop\\out.txt", ios::out);
    ofs << result << endl;
    string str_capacity = "占用容量为：", str_volume = "占用容积为：", str_sum = "总价值为：";
    int sum_capacity = 0, sum_volume = 0, sum_value = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ischoose[i])
        {
            ofs << "选中了：" << i << "物品 "
                << " 重量为：" << w[i] << " 体积为：" << b[i] << " 价值为：" << v[i] << endl;
            sum_capacity += w[i];
            sum_volume += b[i];
            sum_value += v[i];
            str_capacity += to_string(w[i]) + "+";
            str_volume += to_string(b[i]) + "+";
            str_sum += to_string(v[i]) + "+";
        }
    }
    str_capacity.pop_back();
    str_volume.pop_back();
    str_sum.pop_back();
    ofs << str_capacity << " = " << sum_capacity << "  符合容量限制：" << c << endl;
    ofs << str_volume << " = " << sum_volume << "  符合容积限制：" << d << endl;
    ofs << str_sum << " = " << sum_value << endl;
    ofs.close();
}

int main(void)
{
    read();
    solve();
    write();
    return 0;
}

//二维01背包问题
void solve(void)
{
    //设计f(n,c,d)代表现在有n件物品可以选择，当背包容量为c，容积为d时可以获得的最大价值
    int f[n + 1][c + 1][d + 1];
    memset(f, 0, sizeof(f));
    // f[n][c][d] = max(f[n-1][c][d], f[n-1][c-w[n]][d-b[n]] + v[n])  当c>w[n]&&d>b[n]时
    // f[n][c][d] = f[n-1][c][d]   else
    // 当然，我们还要给出初始值，即f[0][j][k] = 0, 这在memset中已经做过了
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            for (int k = 0; k <= d; k++)
            {
                if (w[i] > j || b[i] > k)
                    f[i][j][k] = f[i - 1][j][k]; //如果容量或容积不够，那么就不选取该物品
                else
                    //如果容量和容积都够，那么比较选取该物品和不选取该物品的价值哪个大
                    f[i][j][k] = max(f[i - 1][j][k], f[i - 1][j - w[i]][k - b[i]] + v[i]);
            }
        }
    }

    //查看选取了哪些物品
    for (int i = n, j = c, k = d; i > 0; i--)
    {
        if (f[i][j][k] == f[i - 1][j][k])
            ischoose[i] = false; // 没有变化，说明没有选取
        else
        {
            ischoose[i] = true; // 有变化，说明该物品被选取了
            //更新容量和容积
            j -= w[i];
            k -= b[i];
        }
    }
    cout << "ok"; //运行成功
    result = f[n][c][d];
}