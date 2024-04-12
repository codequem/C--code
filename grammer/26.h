//2022年11月20日23:09:13
//类和动态内存分配
//隐式成员函数
//静态成员类成员的使用


//注意：不能在类声明中初始化静态成员变量，这是因为类声明描述了如何分配内存
//但是并不分配内存

#include <iostream>//注意这里包含了头文件<iostream>

using std::ostream;
using std::istream;

#ifndef string_h_
#define string_h_

class string_
{
private:
	char* str;	
	int len;	
	static int num_strings;//这里只是描述了如何分配内存，并没有内存，自然也不能初始化	
	static const int CINLIM = 80;//但是除去静态整数常量和静态枚举量		
public:
	//构造函数和其他隐式成员函数
	//以下成员函数（作为成员函数都是被该类对象所调用的）在未定义时编译器将会自己定义
	//具体来说有：默认构造函数，复制构造函数，赋值操作符，默认析构函数，地址操作符
	//其中隐式地址操作符返回调用对象的地址，这与我们的初衷一致,这里不做讨论
	//默认析构函数不做任何操作，因此这里也不做讨论

	//如果没有提供任何默认构造函数，c++将创建默认构造函数
	//这个默认构造函数不接受任何参数，也不进行任何操作，它的值全是未知的
	//如果定义了构造函数（下面三个都是）,c++将不会定义默认构造函数
	//构造函数和默认构造函数是不同的，默认构造函数只能有一个（否则产生二义性），而构造函数没有这个限制
	//默认构造函数有两种情况：1.这个构造函数参数列表为空 2.这个构造函数的参数列表里所有参数都有默认值
	string_(const char* s);
	string_();//这不是默认构造函数，这是显式的默认构造函数，默认构造函数的定义是空的，但是这个只是参数列表是空的
	//它可以有用户定义的操作,可以有定义的初始化值。在这里这个函数是这个类的默认构造函数

	//复制构造函数：用于将一个对象复制到新创建的对象中，也就是说，它用于初始化过程中，而不是常规的赋值过程中
	
	
	//类的复制构造函数原型通常为：class_name(const class_name &);
	 
	
	//对于复制构造函数要知道何时调用和有何功能
	//1.何时调用：新建一个对象并将其初始化为同类现有对象时，复制构造函数将被调用，但是并不像字面上那样简单
	//假设motto是一个string_对象，以下四种声明都将调用复制构造函数
	//string_ ditto(motto);
	//以下两种情况可能直接使用复制构造函数创建metoo和also，也可能先利用复制构造函数生成一个临时对象，然后将临时对象赋给他们
	//string_ metto=motto;
	//string_ also=string_(motto);
	//string_ pstring_=new string_(motto);//这种情况使用motto初始化一个匿名对象，并将新对象的地址赋给指针
	//实际上每当程序生成了对象副本时，编译器都将会使用复制构造函数，具体地说，每当函数按值传递对象或函数返回对象，都将使用复制构造函数
	//记住：按值传递意味着创建原始变量的一个副本，编译器生成临时对象时，也将使用复制构造函数
	//因为按值传递对象将调用复制构造函数，因此应该按引用传递对象，这样可以节省调用复制构造函数的时间以及储存新对象的空间
	//有何功能：
	//默认的复制构造函数逐个复制非静态成员，复制的是成员的值（浅度复制），如果成员本身就是类对象，则将使用这个类的复制构造函数来复制成员对象
	//静态变量不受影响，因为他们属于整个类，而不是各个对象
	//但是有一个显然的问题，对于指针，隐式的复制构造函数直接复制了本体的地址给一个临时对象，而这个临时对象会立刻过期
	//从而调用析构函数，此时这个临时对象指向的地址的内容将会“隐式”释放，此时不论是使用本体指针指向的内容
	//还是本体消亡时析构函数再次释放指针所指向的位置（注意这个位置因为临时对象已经被释放过一遍了）都会产生严重的后果

	//因此我们要使用显式复制构造函数来解决问题
	string_(const string_&);

	//析构函数
	~string_();//上述所有的构造函数都必须和析构函数匹配（主要说的是new和delete）


	//方法函数
	void string_lower(void);
	void string_upper(void);
	int string_char_appear_nums(const char);
	int length()const { return len; }
	//重载操作符方法
	string_ operator+(const string_&)const;
	string_& operator=(const string_&);
	string_& operator=(const char*);
	char& operator[](int i);
	const char& operator[](int i)const;
	//重载友元操作符
	friend bool operator<(const string_& st, const string_& sl);
	friend bool operator>(const string_& st, const string_& sl);
	friend bool operator==(const string_& st, const string_& sl);
	friend string_ operator+(const string_& st, const char*);
	friend string_ operator+(const char*, const string_&st);
	friend ostream& operator<<(ostream& os, const string_& st);
	friend istream& operator>>(istream& is, string_& st);
	//静态方法
	static int how_many();
};

#endif