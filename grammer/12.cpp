/*2022年11月6日23:11:26
类型转换，结构，枚举，联合
内联函数*/
#include <iostream>

using namespace std;

enum personsex
{
    man,
    woman,
    other = 999,
    tesila
}; //这里就是枚举,其中other的值为999，tesila的值为1000

typedef struct animal
{
    int code;
    //这是联合
    //它里面的两个数据类型在同一时间点只有一个能用
    union
    {
        char type[20];
        double range;
    };
} animal;
//这是结构
typedef struct person
{
    personsex sex;
    int years;
} person;

//内联函数：常规的函数调用将使程序跳到另外一个地方（被调用的函数的地址），并在函数结束时返回
//这种方式对于执行时间长的函数来说没有问题，但是执行时间短的函数运用内联函数会使得运行更快，代价是需要占用更多的内存
//内联函数不允许递归
//语法：
inline double square(return x * x)//函数定义不一定非要放在一行中，但是如果函数定义有多行，他就不太适合做内联函数

//内联函数类似#define，但是define是纯文本替换，但是内联函数不是，它是按函数来替换的
    int main(void)
{
    //自动转换时，将字节占用较大的值赋给字节占用较小的值往往会出错
    //将浮点值赋给整型将会导致数据被截短（直接舍去小数部分），而且浮点数记录的值可能对于整型来说是超范围的
    //强制类型转换：有以下三种方式
    //强制类型转化不会改变变量本身，而是创建一个新的，指定类型的值，可以在表达式中使用这个值
    int a = 5;
    (long int)a; //(typename) value;
    float b = 3.0;
    double c;
    //这里写double(b)会报错，因为这个值是用来参与表达式的，而不是真的把变量的类型改变掉
    c = double(b);         // typename (value);这种方式有函数的意味
    static_cast<short>(a); // static_cast<typename>(value);
    //对于结构，最重要的就是结构之间可以直接赋值
    person chengyifan, liziqi, wangjunjie, haungshengshen;
    chengyifan.sex = man;
    chengyifan.years = 17;
    wangjunjie = chengyifan;
    //对于枚举，在不强制类型转换的情况下，只能将定义枚举时使用的枚举量赋给这种枚举的变量
    liziqi.sex = woman; //合法
    // liziqi.sex=2;//非法，2不是一个枚举量，因此sex类型和int类型不匹配
    //注意，枚举量可提升为int类型，但是int类型不可以自动转换为枚举类型
    liziqi.sex = personsex(1); //如果进行强制类型转换就合法了
}