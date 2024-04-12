/*2022年10月21日14:11:46
测试数组，string类对象
类方法get和getline
类方法size()和函数strlen*/
#include <iostream>
#include <string>//要使用string类，头文件必须包含<string>
#include <cstring>//为了使用strlen函数
using namespace std;
int main(void)
{
	int len1, len2,len3,len4;
	char ch;
	char *ptr1,*ptr2;
	char name1[20];
	char name2[20];
	char name3[20];//静态数组的大小一确定就无法改变了
	char name4[20];
	string animal1,animal2;//string类对象会自己调整长度
	//可以将一个string类对象赋给另一个string类对象，但是不能对数组这么操作
	cin >> name1;//一直读取，遇到空白字符结束
	//因为cin使用空白(空格，制表符，换行符)来确定字符串的界
	//它并没有指定读取的字符数，那么当我们的输入大于数组的大小时会怎么样呢？
	//超出范围的字符将会被舍弃
    //它会将换行符留在缓存区中，这样会让它之后的cin.get()都受到影响
	//但是不要忘记了，如果后面清一色的都是cin>>这种形式，是不会出错的，因为它们从第一个不是空白字符的地方读取
    cin.get();//将这个换行符读取走
	cin.get(ch).get();
	//它读取一个字符并把它赋给ch
	//cin.get(name2, 19);//读取一行，如果到了读取18字符（最后还要自己加一个'0'）或者换行符结束
	//它并不读取走这个换行符，因此我们通常这么写
	cin.get(name3, 19).get();
	//1.不带任何参数的get()可读取缓存区中下一个字符，即使是空白字符，这里我们是想让它读取换行符
	//同样的get函数，但是在c++中可以定义不同的形式参数来定义不同的函数功能
	//也就是说get()和get(name,Arsize)实际上是同名的不同函数
	//这种特性称为函数重载
	//2.get()是一个类方法，因为cin.get(name3, 19)返回一个类对象，该对象随后被用来调用get()函数
	//这种操作称为类成员函数拼接
	cin.getline(name4, 19);//读取一行，如果到了读取18字符（最后还要自己加一个'0'）或者换行符结束
	//它会读取换行符，但是不会将它保存在数组中，它将把换行符丢弃
	//这种表示法说明getline是istream类的一个类方法，它通过对象cin使用
	getline(cin,animal1);//如果要使用这个函数要包含头文件<string>
	//这里没有使用句点表达，说明getline()不是类方法，实际上istream类中没有处理string对象的类方法
	//这里的getline是string类的一个友元函数
	ptr1 = &animal1[0];
	ptr2 = name1;
	//指针指向string对象的首字符的地址实际上就是指向了这个string对象
	cout << ptr1 << endl;
	//当指针类型是char*型时，cout对象将会打印次此地址上的字符串
	cout << "hello,world" << endl;
	//实际上并不是将整个字符串给了cout，传给cout的只是这个字符串的地址（也就是第一个字母的地址）
	cout << (int*)ptr1<< endl;
	//如果我们想要打印字符串的地址，必须先得把这种（char*）指针先转换为其他类型
	len1 = animal1.size();
	//size是一个属于string类的类方法，所以数组无法使用这种方法
	len2 = strlen(name1);
	len3 = strlen(ptr1);//但是strlen只要传入一个char*指针就能用，所以string类和数组都可以使用
	len4 = strlen(ptr2);
	//可以使用数组表示法使用string类对象
	cout << animal1[2] << endl;
	return 0;
}