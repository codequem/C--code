/*2022年11月16日16:55:48
友元，操作符重载*/

#ifndef vector_h_
#define vector_h_

#include <iostream>

namespace VECTOR
{
    class Vector
    {
        private:
        double x;
        double y;//这两个参数是水平距离和垂直距离

        double len;//矢量长度
        double ang;//矢量角度

        char mode;//状态成员，若此值为r则表示直角坐标模式，若此值为p表示极坐标模式

        //私有类方法：//还记得吗，通常使用私有成员函数来处理不属于公有接口的实现细节
        //编写这个类的人可以使用它，但是使用这个类的人不行，这里是设置类成员的值，不必将它置于公有
        void set_len();
        void set_ang();
        void set_x();
        void set_y();

        public:
        //别忘了构造函数和析构函数是不需要返回类型的
        Vector();//构造函数
        Vector(double a,double b,char form='r');//构造函数（重载版本）
        //这里的默认参数不能全给，否则会出现二义性
        ~Vector();//析构函数
        
        void set(double a,double b,char form='r');
        //展示值的函数：
        double xval()const{return x;};
        double yval()const{return y;};
        double angval()const{return ang;};
        double lenval()const{return len;};
        //设置模式;
        void polar_mode();//将模式设置为极坐标
        void rect_mode();//将模式设置为直角坐标
        //操作符重载：注意操作符重载的返回类型一般是用户定义的类型
        Vector operator- (const Vector& opnum)const;
        //如果有如上定义，则不允许再次声明friend Vector operator- (const Vector& opnum1，const Vector& opnum2);
        //看起来两个的特征标不同，但是使用时会同时符合条件，造成二义性错误

        Vector operator+ (const Vector& opnum)const;//加减法
        Vector operator- ()const;//这是取负操作符
        Vector operator* (double n)const;//这种乘法只能用户自定义的类型在前面，因为需要它来调用*，但n不是类成员
        //无法调用类方法，因此就有了友元函数：声明在类声明内，拥有和成员函数（类方法）相同的访问权限，但是非成员函数，不能使用成员操作符调用
        //注意：如果不需要访问私有数据就不需要使用友元
        //友元函数:声明方法，在声明前加friend，注意：在定义时不需要
        friend Vector operator*(const double n,const Vector& opnum);//其后不加const，它压根不依靠对象使用
        //其实这个友元可以替换为下列的非友元函数
        //Vector operator*(const double,const Vector & opnum)
        /* {
            return opnum*n;//这里里面把操作符顺序调过来（利用既有的操作符），并且不需要访问vector的私有数据，因此可以不用友元
        } */

        friend std::ostream& operator<<(std::ostream& os,const Vector &v);//重载<<,让他能和ostream对象来一起显示内容
        //这里必须运用友元，因为要想显示vector对象，必须要访问它的私有数据，但这不必去iostream文件中
        //加入新的函数操作符，只需要让vector类知道如何使用ostream类对象即可
        //这里返回cout对象的引用是因为一个程序中只有一个标准输出，所以全局范围内只有一个cout，若不是返回引用则会多一个cout拷贝
        //而且确保操作的还是同一个输出流，并且这样使得可以cout<<vector1<<vector2(拼接起来用)，要知道这样的实质是每次调用完
        //返回的又是一个cout接着输出的
    };
}
#endif