/*2022年11月19日18:36:27
类的自动转换和强制类型转换*/

#ifndef stonewt_h_
#define stonewt_h_

class stonewt
{
private:
    static const int lbs_per_stn = 14;//pounds per stone
    int stone;//whole stones
    double pds_left;//fractional pounds
    double pounds;//entire weight in pounds
public:
    //构造函数
    stonewt(double lbs);//constructor for double pounds
    stonewt(int stn, double lbs);//constructor for stone,lbs
    stonewt();//default constructor
    //析构函数
    ~stonewt();
    //成员函数
    int stone_to_int();
    void show_lbs()const;//show weight in pounds format
    void show_stn()const;//show weight in stone format
    //转换函数：
    operator int()const;
    //注：
    //转换函数必须是类方法,说明它通过类对象调用，因此不需要指定返回类型
    //转换函数不能指定返回类型,但是定义中要返回指定类型的值
    //转换函数不能有参数
    //不能使用explicit,因为是类成员函数，explicit只能用于类构造函数
};
#endif
