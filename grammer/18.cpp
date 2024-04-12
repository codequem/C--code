/*2022年11月10日21:47:24
说明符与限定符*/

#include <iostream>

using namespace std;

int main(void)
{
    //以下是存储说明符
    //auto,register,static,extern,mutable
    //在同一个声明中不能使用多个说明符
    //extern表明是引用声明，即声明引用在其他地方定义的变量
    //static在用于作用域为整个文件的声明中时，表示内部链接性，被用于局部声明中时，表示局部变量的储存持续性是静态的，无链接性

    //以下是cv-限定符
    //const,volatile
    //mutable是配合const使用的，例：
    struct data{
        char name[30];
        mutable int accesses;
    };
    const data veep={"aaacyf",0};
    //veep.name="aaa";//非法的，因为是const变量
    veep.accesses++;//合法，得益于mutable
    //mutable 说明即使结构或者变量是const，其某个成员也可以被修改

    //在c++中，const限定符默认全局变量的链接性为内部，即在c++，全局const定义就像是使用了static说明符一样
    //而通常的默认情况下全局变量的连接性为外部
    //这是为了防止将常量放在头文件中产生重复定义，因为在多个文件中使用这些变量，如果是外部链接将会报错，但是内部链接不会

    //允许用extern来覆盖默认的内部链接性
}