/*2022年11月10日00:12:22*/
//应该放在头文件中的内容：
//函数原型，使用#define或const定义的符号常量，结构声明，类声明，模板声明，内联函数

//本文件包含结构声明和使用这些结构的函数的原型
//结构模板和函数功能原型

//结构模板
#ifndef COORDIN_H_//即if not define
#define COORDIN_H_

struct polar{
    double distance;
    double angle;
};
struct rect{
    double x;
    double y;
};

//函数原型
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif

/* #ifndef COORDIN_H_
……………
#endif */
//这块代码块意为：仅当以前没有使用预处理器指令#define定义名称COORDIN_H_时，
//才处理#ifndef和#endif之间的语句
//只要把#define用于名称就可以完成该名称的定义，因此我们在头文件中定义这样一个常量，相当于一个标记
//只要引用过一次这个头文件，再次引用它就会让它直接跳出，达到保护重复定义的效果