#include <iostream>
#include <utility>
#include <cmath>
#include <string>

using namespace std;

const string name ="E22214111 程一帆";

class Point
{
public:
    double x;
    double y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class Interval
{
private:
    double start;
    double end;

public:
    // Interval(double start, double end) : start(start), end(end) {}
    Interval(double start = 0, double end = 0)
    {
        this->start = min(start, end);
        this->end = max(start, end);
    }
    Interval(const Interval &i) : start(i.start), end(i.end) {}
    bool isempty() const
    {
        return end <= start;
    }
    double getlength() const
    {
        if (this->isempty())
            return 0;
        else
            return end - start;
    }
    double getstart() const { return start; }
    double getend() const { return end; }
    void setstart(double start)
    {
        this->start = start;
    }
    void setend(double end)
    {
        this->end = end;
    }
    Interval I_intersect(Interval other) const
    {
        Interval result(0, 0);
        result.start = max(other.start, start);
        result.end = min(other.end, end);
        return result;
    }
    Interval I_union(Interval other) const
    {
        Interval result(0, 0);
        result.start = min(other.start, start);
        result.end = max(other.end, end);
        return result;
    }
};

class Rect
{
private:
    Interval herizontal;
    Interval vertical;
    Point topleft;
    Point bottomright;

public:
    Rect(Point topleft, Point bottomright)
    {
        herizontal.setstart(min(topleft.x, bottomright.x));
        herizontal.setend(max(topleft.x, bottomright.x));
        vertical.setstart(min(topleft.y, bottomright.y));
        vertical.setend(max(topleft.y, bottomright.y));
        this->topleft.x = topleft.x;
        this->topleft.y = topleft.y;
        this->bottomright.x = bottomright.x;
        this->bottomright.y = bottomright.y;
    }
    Rect(const Rect &r) : herizontal(r.herizontal), vertical(r.vertical) {}
    double getArea() { return herizontal.getlength() * vertical.getlength(); }
    bool isempty()
    {
        return herizontal.isempty() || vertical.isempty();
    }

    Point gettopLeft()
    {
        return topleft;
    }

    Point getbottomRight()
    {
        return bottomright;
    }

    Rect R_intersect(Rect other)
    {
        Rect result(other);
        result.herizontal = other.herizontal.I_intersect(herizontal);
        result.vertical = other.vertical.I_intersect(vertical);
        return result;
    }
    Rect R_union(Rect other)
    {
        Rect result(other);
        result.herizontal = other.herizontal.I_union(herizontal);
        result.vertical = other.vertical.I_union(vertical);
        return result;
    }
    double IoU(Rect other)
    {
        Rect Iresult = this->R_intersect(other);
        Rect Uresult = this->R_union(other);
        double result = 0;
        if (Iresult.isempty() || Uresult.isempty())
            return 0;
        result = Iresult.getArea() / Uresult.getArea();
        return result;
    }
    void showRect()
    {
        cout << "Rectangle Info:" << endl;
        cout << "topLeft: " << this->gettopLeft().x << ',' << this->gettopLeft().y << endl;
        cout << "bottomRight: " << this->getbottomRight().x << ',' << this->getbottomRight().y << endl;
        cout << "Width: " << herizontal.getlength() << endl;
        cout << "Height: " << vertical.getlength() << endl;
        cout << "Area: " << this->getArea() << endl;
        // cout << "IoU: " << this->IoU() << endl;
    }
};

int main(void)
{
    cout<<name<<endl;
    Rect r1(Point(0, 1), Point(1, 0));
    Rect r2(Point(0, 3), Point(5, 0));
    Rect r3(Point(-1, 1), Point(2, -2));

    r1.showRect();
    r2.showRect();
    r3.showRect();
    cout << "r1 IoU r2:" << r1.IoU(r2) << endl;
    cout << "r2 IoU r3:" << r2.IoU(r3) << endl;
    cout << "r1 IoU r3:" << r1.IoU(r3) << endl;
}