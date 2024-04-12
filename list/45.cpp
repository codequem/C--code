/*2023年4月18日15:54:36*/
#include <iostream>
#include <stack>
#include <string>
#include <windows.h>

using namespace std;

bool check(string str);

int main(void)
{
    //回文测试
    string a;
    string b;
    string c;
    cin>>a>>b>>c;
    cout << boolalpha <<"a: "<< check(a) << ' ' <<"b: "<< check(b) << ' '<<"c: " << check(c) << endl;
    system("pause");
    return 0;
}

bool check(string str)
{
    stack<char> judge;
    for (int i = 0; i <= str.size() / 2 - 1; i++)
        judge.push(str[i]); //入栈一半字符
    for (int sta = ((str.size() & 1) ? str.size() / 2 + 1 : str.size() / 2); sta < str.size(); sta++)
    {
        if (judge.top() == str[sta])
            judge.pop(); //剩下的一个个和栈顶比较
        else
            return false; //有一个不匹配就false
    }
    return true;
}