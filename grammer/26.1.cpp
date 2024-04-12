#include "string_.h"
#include <cstring>

using std::cout;
using std::cin;


//初始化静态类成员
int string_::num_strings = 0;

//静态方法
int string_::how_many()//定义出不必写static，但是声明出需要，静态方法是用于改变静态成员的
//不依靠对象使用，直接使用类名和作用域操作符调用它（当他在public中声明）
//因此它连this指针都没有，只能用于改变静态类成员（因为不使用对象）
{
	return num_strings;
}

//构造函数和其他隐式成员函数
	//以下成员函数（作为成员函数都是被该类对象所调用的）在未定义时编译器将会自己定义
	//具体来说有：默认构造函数，复制构造函数，赋值操作符，默认析构函数，地址操作符
	//其中隐式地址操作符返回调用对象的地址，这与我们的初衷一致,这里不做讨论
	//默认析构函数不做任何操作，因此这里也不做讨论

//构造函数
string_::string_(const char* s)//非默认构造函数
{
	len = std::strlen(s);//设置长度
	str = new char[len + 1];//分配空间，注意这里用的是new[]
	std::strcpy(str, s);//初始化指针，实际上是把传入的字符复制一份到指针中
	num_strings++;//统计一共有几个strings
}

string_::string_()//默认构造函数
{
	//设置默认值
	len = 4;
	str = new char[1];//注意，因为后面的析构函数要用到delete[]，构造函数必须和析构函数相匹配
	str[0] = '\0';
	num_strings++;
}

//显式复制构造函数（如果不给出，编译器将会自动给一个按值传递的复制构造函数，当使用指针时这种按值传递是不能满足要求的）
//这玩意也属于构造函数，没有返回值
string_::string_(const string_& st)//
{
	num_strings++;
	len = st.len;//常规的值是可以按值传递的
	str = new char[st.len+1];//但是对于指针，我们要传递的是它的信息
	std::strcpy(str, st.str);
}

//析构函数
string_::~string_()
{
	delete[]str;//对与构造函数中使用了new的，析构函数就展示了它最大的作用
	//释放内存，当然没有使用new的使用时，析构函数可以是空实现
	num_strings--;
}

void string_::string_lower(void)
{
	for (int i = 0; i <=len; i++)
		if (this->str[i] >= 65 && this->str[i] <= 90)
			str[i] |= 32;
}

void string_::string_upper(void)
{
	for (int i = 0; i <len; i++)
		if (this->str[i] >= 97 && this->str[i] <= 122)
			str[i] &=(~32);
}

int string_::string_char_appear_nums(const char a)
{
	int sum = 0;
	for(int i=0;i<len;i++)
		if(this->str[i]==a)
			sum++;
	return sum;
}

string_ string_::operator+(const string_&st)const
{
	string_ re;
	re.len = len + st.len;
	re.str = new char[re.len + 1];
	strcpy(re.str, str);
	strcat(re.str, st.str);
	return re;
}

//赋值操作符（这是只能由类成员函数重载的操作符）//也就是只能作为方法
//c允许结构赋值，c++允许对象赋值，这都是自动为类重载赋值操作符实现的
//原型如下：class_name &(这前面的是返回类型) class_name::（类名和作用域操作符）operator=(const class_name &)
//本来编译器默认生成的按值赋值的赋值操作符就行，但是很不幸，这里用了指针，就不是简单的按值传递可以的了
string_& string_::operator=(const string_&st)//这一个是为了让string类对象赋值给string类对象的
{
	//对于赋值操作，可能是自赋值（a=a）或非自赋值（a=b）
	if (this == &st)//假设是自己赋给自己
	{
		return *this;//那就啥也不干(实际上这两行是为了防止将对象赋给自身）
	}
	delete[]str;//赋值会覆盖之前的值，所以要先清掉原有的数据
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	//赋值操作并不创建新的对象，因此string_nums不变
	return *this;//这里是为了串联赋值（a=b=c），因此要返回一个指向调用对象的引用
}

string_& string_::operator=(const char* s)//这一个是为了将c风格字符串赋值给string类对象，主要是c风格字符串
{	//是不需要进行创建对象删除对象的操作的，如果没有这个函数，只有上面的那个赋值操作符时
	//要想  string_ temp="china",将会先使用构造函数string_（const char*s）来创建一个临时string_对象，其中
	//包含字符串（"china")的拷贝,然后利用上面那个函数赋好值，然后再用析构函数来删除这个临时对象
	//但是为了提高效率，我们可以重载操作符（避免创建和删除对象）
	delete[]str;
	len = strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char& string_::operator[](int i)//对于array[0],array是第一个操作数，0是第二个操作数
{
	return str[i];//这里直接借用char数组的[ ]
	//返回引用是为了给特定元素赋值,如：
	//string_ means("might") ; means[0]='r';
	//第二条语句将被转化为means.operator[](0)='r';
	//这里将r赋给方法的返回值，又因为返回值是means的引用，以此达到想要的效果
}

const char& string_::operator[](int i) const
{
	//如果只有上面的一个定义，则对于const string_answer("fuuuu");
	//cout<<answer[1];将出错，因为answer是常量，而上面的定义无法保证不改变数据
	//又因为有没有const是两个特征标，所以这里提供仅给const string对象使用的版本
	return str[i];
}
 
//操作符重载
bool operator<(const string_& st, const string_& sl)
{
	return (std::strcmp(st.str, sl.str) < 0);//strcmp,若第一个参数位于第二个参数之后返回一个正值（b-a>0）
}

bool operator>(const string_& st, const string_& sl)
{
	return sl < st;//如果a>b,则b<a
}

bool operator==(const string_& st, const string_& sl)
{
	return (std::strcmp(st.str, sl.str) == 0);
}

string_ operator+(const string_& st, const char* sl)
{
	string_ re;
	re.len = st.len + strlen(sl);
	re.str = new char[re.len + 1];
	strcpy(re.str, st.str);
	strcat(re.str, sl);
	return re;
}

string_ operator+(const char*sl, const string_& st)
{
	string_ re;
	re.len = st.len + strlen(sl);
	re.str = new char[re.len + 1];
	strcpy(re.str, sl);
	strcat(re.str, st.str);
	return re;
}

ostream& operator<<(ostream& os,const string_& st)//友元函数
{
	os <<st.str;//os是ostream类对象，直接当cout使用
	return os;
}

istream& operator>>(istream& is,string_& st)
{
	char temp[string_::CINLIM];
	is.get(temp, string_::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')//遇到EOF时istream对象返回0
		continue;
	return is;
}