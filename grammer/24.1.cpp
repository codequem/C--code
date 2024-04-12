/*2022年11月16日21:21:57
类，友元，运算符重载*/

#include "24.h"
#include <cmath>

using std::atan2;
using std::cos;
using std::cout;
using std::endl;
using std::sin;

namespace VECTOR
{
    const double Rad_to_deg = 57.2957795130823;

    void Vector::set_len()
    {
        len = sqrt(x * x + y * y); //距离（极坐标）
    }

    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0;
        else
            ang = atan2(y, x); // atan2(y,x)返回点与原点连线与x轴正半轴的夹角（弧度制）
    }

    void Vector::set_x()
    {
        x = len * cos(ang);
    }

    void Vector::set_y()
    {
        y = len * sin(ang);
    }

    Vector::Vector()
    {
        x = y = len = ang = 0;
        mode = 'r';
    }

    Vector::Vector(double a, double b, char form)
    {
        if (form == 'r')
        {
            x = a;
            y = b;
            mode = form;
            set_ang();
            set_len();
        }
        else if (form == 'p')
        {
            len = a;
            ang = b / Rad_to_deg;
            mode = form;
            set_x();
            set_y();
        }
        else
        {
            cout << "incorrect 3rd argument to Vector()" << endl
                 << "vector set to 0\n";
            x = y = len = ang = 0;
            mode = 'r';
        }
    }

    Vector::~Vector() //没用new，所以啥也没有
    {
    }

    void Vector::polar_mode()
    {
        mode = 'p';
    }

    void Vector::rect_mode()
    {
        mode = 'r';
    }

    Vector Vector::operator-(const Vector &opnum) const
    {
        return Vector(x - opnum.x, y - opnum.y);
    }

    Vector Vector::operator+(const Vector &opnum) const
    {
        return Vector(x + opnum.x, y + opnum.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    Vector operator*(const double n,const Vector& opnum)//注意虽然是友元但是定义的时候不加friend
    //并且不需要用Vector::因为它不是类方法
    {
        return opnum*n;
    }

    std::ostream& operator<<(std::ostream& os, const Vector& v)
    {
        if (v.mode == 'r')
            os << "(x,y)=(" << v.x << ',' << v.y << ")";
        else if (v.mode == 'p')
        {
            os << "(l,a)=(" << v.len << ',' << v.ang * Rad_to_deg << ")";
        }
        else
            os << "Vector object mode is invaild";
        return os;
    }
}