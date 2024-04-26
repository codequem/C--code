#include <iostream>
#include <cmath>
using namespace std;

const double g = 9.8;
const double pi = 3.1415926;
const double eps = 1e-4;

double delta(double a, double b, double c)
{ // 计算δ
    return b * b - 4 * a * c;
}

double answer1(double a, double b, double c)
{ // 求解一元二次方程(小根)
    double ans = (-b - sqrt(delta(a, b, c))) / (2 * a);
    return ans;
}

double answer2(double a, double b, double c)
{ // （大根）
    double ans = (-b + sqrt(delta(a, b, c))) / (2 * a);
    return ans;
}

double dis(double x1, double y1, double x2, double y2)
{ // 计算距离
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double location2x(double x0, double w, double beta, double t)
{ // 目标位置x
    return x0 + w * cos(beta * pi / 180) * t;
}

double location2y(double y0, double w, double beta, double t)
{ // 目标位置y
    return y0 + w * sin(beta * pi / 180) * t;
}

double time(double x, double y, double v)
{ // 计算时间
    double a = g * g / 4, b = g * y - v * v, c = x * x + y * y;
    double del = delta(a, b, c);
    if (del < 0)
    {
        return 0; // 此时方程无解，直接返回0
    }
    double ans1 = answer1(a, b, c), ans2 = answer2(a, b, c);
    if (ans1 > 0)
    {
        return sqrt(ans1); // 小根大于零时取小根
    }
    else
    {
        return sqrt(ans2);
    }
}

double result(double x0, double y0, double w, double beta, double t)
{
    double x, y;
    x = x0 + w * cos(beta * pi / 180) * t;
    y = g * t * t / 2 + y0 + w * sin(beta * pi / 180) * t;
    return atan(y / x) * 180 / pi;
}

int main()
{
    cout << "路昺豪 E22214087" << endl;
    double v, w, beta, thea;
    double x[301], y[301], t[301];
    cout << "请依次输入:" << endl;
    cout << "炮弹初速度v,";
    cout << "敌方目标初速度w,";
    cout << "敌方目标初始角度beta,";
    cout << "敌方目标初始位置(x0,y0)" << endl;
    cin >> v >> w >> beta >> x[0] >> y[0];

    x[1] = x[0], y[1] = y[0];   // 赋值x1,y1
    t[1] = time(x[1], y[1], v); // 计算第一次迭代的命中时间
    x[2] = location2x(x[1], w, beta, t[1]);
    y[2] = location2y(y[1], w, beta, t[1]); // 计算第二次迭代的坐标
    int i = 1, flag = 1;                    // 定义标志flag
    while (dis(x[i], y[i], x[i + 1], y[i + 1]) >= eps)
    {
        t[i + 1] = time(x[i + 1], y[i + 1], v); // 计算本次迭代的时间
        if (t[i + 1] == 0)
        {
            flag = 0;
            break; // t无解时标志更新。退出循环
        }
        x[i + 2] = location2x(x[0], w, beta, t[i + 1]);
        y[i + 2] = location2y(y[0], w, beta, t[i + 1]); // 计算下一次迭代的坐标
        i++;
    }
    if (flag == 1)
    {
        thea = result(x[0], y[0], w, beta, t[i]);
        cout << endl
             << "最佳发射角度为：" << thea << "°" << endl;
        cout << "命中时间：" << t[i] << "s" << endl;
        cout << "命中位置坐标："
             << "(" << x[i + 1] << "," << y[i + 1] << ")" << endl;
    }
    if (flag == 0)
    {
        cout << endl
             << "炮弹无法命中" << endl;
    }
    return 0;
}
