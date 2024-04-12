/*2022年10月21日23:29:25
测试cin>>句法功能*/
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    char array1[20];
    char array2[20];
    char array3[20];
    char array4[20];
    cin >> array1 >> array2 >> array3;//只留下了最后一个'\n'，前两个都丢弃了
    //读取顺序是按1,2,3来的，因为先cin >> array1返回一个cin对象再进行接下来的操作
    cin >> array4;//这种格式是不会受到换行符干扰的，会跳过换行符和空格
    //当cin读取到不符合的输入时会发生什么呢
    int a;
    cin>>a;
    //如果这里输入了一个字母，那么cin将设置一个错误条件，此时我们就要使用cin.clean()重置输入
    //并且用cin.get()将不合法的数据给读取走，因为不合法的数据仍然在缓存区中
    if(!cin)
    {
        cin.clear();
        /*while(cin.get()!='\n')
        continue;*/
        //或者使用类方法sync
        cin.sync();//清空输入流
        //或者使用cin.ignore()方法，他能够从输入流中提取字符，提取的字符将被ignore，它接受两个参数
        //cin.ignore(int a,char ch),如果计数值达到a或者被抛弃的字符是ch时函数执行终止，当然它也会清除它遇到的第一个ch字符
        //即：你可以使用sync将输入流中的字符全部清除，但是你可以使用ignore将输入流中的指定字符清除
    }
    return 0;
}