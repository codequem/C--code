#include <iostream>
#include <cmath>

using namespace std;

class Point{
    public:
    Point(int xx = 0, int yy = 0)
    {
        x =xx;
        y =yy;
    }
    Point(Point& p);
    int getX(){return x;}
    int getY(){return y;}
    private:
    int x,y;
}
Point::Point(Point &p)
{
    x=p.x;
    y=p.y;
}