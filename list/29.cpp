/*2023年1月15日21:30:05
计算一个多项式的正确值，允许使用+，-，*，/,(,),[,],{,}
涉及后缀表达式的计算，标准(中缀)表达式向后缀表达式的转换，判断表达式是否平衡*/
//算法不难。但是难在如何在字符表达式中提取出数字
#include <Windows.h>
#include <iostream>
#include <string>
#include <stack>
#define N 100

using std::stack;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void str_to_postfix(string& expression);
bool blance_judge(const string& expression);
double calculated_postfix(const string & expression);
double calculated_result(const string& expression);
double detect_digit(const string& expression);

double Digital_set[N];
stack<double> digit_stack;
stack<char> 

int main (void)
{
    string input;
    cin>>input;
    calculated_result(input);
    system("pause");
    return 0;
}

double calculated_result(const string& expression)
{
    if(!blance_judge(expression))
    {
        cout<<"Illegal input!!!"<<endl;
        return 0;
    }
    
}
double detect_digit(const string& expression)
{

}
double calculated_postfix(const string & expression)
{

}
void str_to_postfix(string& expression)
{

}

bool blance_judge(const string& expression)
{
    char opensymbols[3]={'(','[','{'};
    char closesymbols[3]={')',']','}'};
    stack<char> sign_judge;
    for(int i=0;i<expression.length();i++)
    {
        for(int j=0;j<3;j++)
        {
            if(expression[i]==opensymbols[j])
                sign_judge.push(expression[i]);
            if(expression[i]==closesymbols[j])
            {
                if(sign_judge.empty()||(expression[i]-sign_judge.top()>2))
                return false;
                sign_judge.pop();
            }
        }
    }
    return (!sign_judge.empty())?false:true;
}