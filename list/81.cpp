#include <iostream>
#include <cmath>
#include <string>
#define gravity 9.8
#define pi 3.1415956
#define studentID "XXXXXXX"

using namespace std;

struct Target
{
    double x;
    double y;
    double distance(Target t)
    {
        return sqrt((x - t.x) * (x - t.x) + (y - t.y) * (y - t.y));
    }
};

void calculate(double v, double w, double angle, double x0, double y0);
double quadraticRoot(double A, double B, double C, bool &valid);

int main(void)
{
    double v, w, angle, x0, y0;
    cout << studentID << endl;
    cin >> v >> w >> angle >> x0 >> y0;
    calculate(v, w, angle, x0, y0);
    return 0;
}

void calculate(double v, double w, double angle, double x0, double y0)
{
    Target s, n;
    s.x = n.x = x0;
    s.y = n.y = y0;
    double t2 = 0, t = 0;
    bool right = true;
    double wx = w * cos(angle * pi / 180.0);
    double wy = w * sin(angle * pi / 180.0);
    do
    {
        s.x = n.x;
        s.y = n.y;
        t2 = quadraticRoot(1 / 4 * gravity * gravity, gravity * s.y - v * v, s.x * s.x + s.y * s.y, right);
        if (!right)
            break;
        t = sqrt(t2);
        n.x = x0 + wx * t;
        n.y = y0 + wy * t;
    } while (s.distance(n) >= 1e-4);
    if (!right)
    {
        cout << "炮弹无法命中目标！" << endl;
    }
    else
    {
        double ang = atan2(y0 + wy * t + 1 / 2 * gravity * t * t, x0 + wx * t) * 180.0 / pi;
        cout << "发射角" << ang << ","
             << " 时间  " << t << "s,"
             << " 命中点  " << s.x << "," << s.y << endl;
    }
}

double quadraticRoot(double A, double B, double C, bool &valid)
{
    double discriminant = B * B - 4 * A * C;
    double x1, x2;
    if (discriminant < 0)
    {
        valid = false;
        return -1;
    }
    if (A == 0)
    {
        x1 = x2 = -1 * C / B;
        if (x1 < 0)
        {
            valid = false;
            return -1;
        }
        else
            return x1;
    }
    else
    {
        valid = true;
        return (-B + sqrt(discriminant)) / (2 * A);
    }
}
