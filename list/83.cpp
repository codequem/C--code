#include <iostream>
#include <cmath>
using namespace std;
#define N 10000
#define min 1e-4 // 定义阈值
#define g 9.8
#define PI 3.1415926
int cmp(double x0, double y0, double x1, double y1) // 比较判断是否继续迭代
{
    if (((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1)) >= min * min)
        return 1;
    else
        return 0;
}
double fun(double x, double y, int v) // 解方程
{
    double t1, t2;
    double A = (g * g) / 4;
    double B = y * g - v * v;
    double C = x * x + y * y;
    double k = B * B - 4 * A * C;
    if (k < 0)
        return 0;
    else
    {
        t1 = (-B + sqrt(k)) / (2 * A);
        t2 = (-B - sqrt(k)) / (2 * A);
        if (t2 > 0)
            return sqrt(t2);
        else
            return sqrt(t1);
    }
}

int main()
{
    cout << "刘俊杰 E22214099" << endl;
    int v, w, a; // 炮弹速率v,敌方目标速率w，敌方发射方向a
    int i = 1;
    double x[N], y[N]; // 坐标
    double t;          // 炮弹击中目标的时间
    int flag = 1;      // 标记是否能命中目标
    double s, c;
    double ans; // 发射角度
    cout << "炮弹速率v=";
    cin >> v;
    cout << "敌方目标速率w=";
    cin >> w;
    cout << "敌方发射方向a=";
    cin >> a;
    cout << "敌方目标初始位置为";
    cin >> x[0] >> y[0];
    x[1] = x[0];
    y[1] = y[0];
    do
    {
        t = fun(x[i], y[i], v);
        if (t == 0)
        { // 如果方程无解，说明炮弹无法命中目标
            flag = 0;
            break;
        }
        else
        { // 更新下一次瞄准点坐标
            x[i + 1] = x[0] + w * t * cos(a * PI / 180);
            y[i + 1] = y[0] + w * t * sin(a * PI / 180);
        }
        i++;
    } while (cmp(x[i - 1], y[i - 1], x[i], y[i])); // 不断迭代，直到距离小于给定的阈值
    if (flag == 0)
    {
        cout << "炮弹无法命中目标" << endl;
    }
    else
    { // 计算发射角
        c = x[i] / (v * t);
        s = (y[i] + g * t * t / 2) / (v * t);
        ans = atan(s / c) * 180 / PI;
        printf("为了尽可能快地命中目标，发射角应为%.2f\n", ans);
        printf("命中时间为%.2f\n", t);
        printf("命中位置为（%.2f，%.2f)", x[i], y[i]);
    }
    return 0;
}