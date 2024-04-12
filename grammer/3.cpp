/*2022年10月21日23:28:44
测试文本文件的输入和输出*/
#include <iostream>
#include <fstream>
using namespace std;
int main (void)
{
    ofstream outfile("E:\\awwa.txt");
    //outfile.open("C:\\用户\\cyf\\桌面\\awwa.txt");
    //应该是不能包含中文路径
    outfile<<"hello,world!"<<endl;
    return 0;
}