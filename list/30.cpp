#include <iostream>
#include <direct.h>
#include <cstring>
#include <string>
#include <windows.h>

using namespace std;

int main (void)
{
    system("cls");
    string path;
    char *p=new char[100];
    strcpy(p,path.c_str());
    getcwd(p,100);//这玩意可以获取当前文件的执行路径
    path=p;
    cout<<path<<endl;
    system("pause");
    return 0;
}