/*2022年11月10日00:13:24*/

//本文件包含函数定义

#include <iostream>
#include <cmath>
#include "16.h"

polar rect_to_polar(rect xypos)
{
    using namespace std;
    polar answer;

    answer.distance=sqrt(xypos.x*xypos.x+xypos.y*xypos.y);
    answer.angle=atan2(xypos.y,xypos.x);
    return answer;
}

void show_polar(polar dapos)
{
    using namespace std;
    const double Red_to_deg=57.29577951;

    cout<<"distance="<<dapos.distance;
    cout<<",angle="<<dapos.angle*Red_to_deg;
    cout<<"degrees\n";
}