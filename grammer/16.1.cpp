/*2022年11月9日17:27:57
单独编译*/
//并不是这么写不行，只是vsc每次编译是单文件编译，可以在task.json文件中更改，
//也可以调用控制台运用gcc的编译指令来多文件编译链接
//编译指令如下D:/MinGW/mingw64/bin/g++.exe -fdiagnostics-color=always -g 
//E:\CODE\C++code\grammar\16.1.cpp E:\CODE\C++code\grammar\16.2.cpp -o E:\CODE\C++code\grammar\16.1.exe

//将程序分成三个部分
//头文件：包含结构声明和使用这些结构的函数的原型
//源代码文件：包含与结构有关的函数的代码
//源代码文件：包含调用与结构相关的函数的代码

//本文件包含调用与结构有关的函数的代码

//不要将含函数定义和变量声明写到头文件中，这样极有可能导致错误
//应该放在头文件中的内容：
//函数原型，使用#define或const定义的符号常量，结构声明，类声明，模板声明，内联函数

//在IDE中，不要将头文件加入到工程列表中，也不要在源代码文件中使用#include来包含其他的源代码文件（这将导致多重声明）
#include <iostream>
#include "16.h"
using namespace std;

int main(void)
{
    rect rplace;
    polar pplace;

    cout<<"enter the x and y values:";
    while(cin>>rplace.x>>rplace.y)
    {
        pplace=rect_to_polar(rplace);
        show_polar(pplace);
        cout<<"Next two numeber(q to quit)：";
    }
    cout<<"Bye!\n";
    return 0;
}