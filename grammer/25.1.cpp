/*2022年11月19日18:36:27
类的自动转换和强制类型转换*/

#include <iostream>
#include "stonewt.h"
using std::cout;

stonewt::stonewt(double lbs)//接受一个参数的构造函数可以将该类型以及能转换为该类型的类型转换为对应的类数据成员类型
{
    stone = int(lbs);
    pds_left = int(lbs) % lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

stonewt::stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * lbs_per_stn + lbs;
}

stonewt::stonewt()
{
    stone = pds_left = pounds = 0;
}

stonewt::~stonewt()
{

}

int stonewt::stone_to_int()
{
    return int(pounds + 0.5);
}

void stonewt::show_lbs()const
{
    cout << pounds << "pounds\n";
}

void stonewt::show_stn()const
{
    cout << stone << "stone," << pds_left << "pounds\n";
}

stonewt::operator int() const
{
    return int(pounds + 0.5);//这里的int转换是四舍五入
    //虽然没有返回类型，但是要返回对应类型的值
}