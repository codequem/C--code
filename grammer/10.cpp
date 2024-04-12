/*2022年10月28日23:30:44
string类和常见的字符串处理函数*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;

int main (void)
{
//string的构造形式：
    //string str;生成空字符串
    //string s(str);生成字符串为str的复制品
    //string s(str,strbegin,strlen);将字符串str中从下标strbegin开始、长度为strlen的部分作为字符串初值
    //string s(cstr, char_len);以C_string类型cstr的前char_len个字符串作为字符串s的初值
    //string s(num ,c);生成num个c字符的字符串

//实例：
    string str1="cyf";         //生成空字符串
    string str2("123456789");  //生成"1234456789"的复制品
    string str2_1(str1);       //生成str1的复制品
    string str3("12345", 0, 3);//结果为"123"
    string str4("012345", 5);  //结果为"01234"
    string str5(5, '1');       //结果为"11111"

//string的大小和容量：
    //1. size()和length()：返回string对象的字符个数，他们执行效果相同。
    //2. max_size()：返回string对象最多包含的字符数，超出会抛出length_error异常
    //3. capacity()：重新分配内存之前，string对象能包含的最大字符数

//实例：
    cout<<"str1,size="<<str1.size()<<endl;
    cout<<"str1,size="<<str1.length()<<endl;
    cout<<"string_max_char_nums="<<str1.max_size()<<endl;//max_size()方法借助string对象使用
    cout<<"str1_expect_capacity="<<str1.capacity()<<endl;

//string的字符串比较：
    //1. C ++字符串支持常见的比较操作符（>,>=,<,<=,==,!=），甚至支持string与C-string的比较(如 str<”hello”) 
    //在使用>,>=,<,<=这些操作符的时候是根据“当前字符特性”将字符按字典顺序进行逐一的比较。字典排序靠前的字符小，  
    //比较的顺序是从前向后比较，遇到不相等的字符就按这个位置上的两个字符的比较结果确定两个字符串的大小(前面减后面)
    //同时，string (“aaaa”) <string(aaaaa)
    //2. 另一个功能强大的比较函数是成员函数compare()，他支持多参数处理，支持用索引值和长度定位子串来进行比较。 
    //他返回一个整数来表示比较结果，返回值意义如下：0：相等 ，1：大于 ，-1：小于

//实例：
    // (A的ASCII码是65，a的ASCII码是97)
    // 前面减去后面的ASCII码，>0返回1，<0返回-1，相同返回0
    string A("aBcd");
    string B("Abcd");
    string C("123456");
    string D("123dfg");
    // "aBcd" 和 "Abcd"比较------ a > A
    cout << "A.compare(B):" << A.compare(B)<< endl;            // 结果：1
    // "cd" 和 "Abcd"比较------- c > A
    cout << "A.compare(2, 3, B):" <<A.compare(2, 3, B)<< endl; // 结果：1
    // "cd" 和 "cd"比较 
    cout << "A.compare(2, 3, B, 2, 3):" << A.compare(2, 3, B, 2, 3) << endl;  // 结果：0
    // 由结果看出来：0表示下标，3表示长度
    // "123" 和 "123"比较 
    cout << "C.compare(0, 3, D, 0, 3):" <<C.compare(0, 3, D, 0, 3) << endl;    // 结果：0

//string的插入：push_back()和insert():
    string s1;
    // 尾插一个字符
    s1.push_back('a');
    s1.push_back('b');
    s1.push_back('c');
    cout<<"s1:"<<s1<<endl; // s1:abc
    // insert(pos,char):在制定的位置pos前插入字符char
    s1.insert(s1.begin(),'1');
    cout<<"s1:"<<s1<<endl; // s1:1abc

//string的遍历：借助迭代器或者下标法:这里注重使用反向迭代器进行逆向输出
    string ss1("abcdef"); // 调用一次构造函数
    // 方法一： 下标法
    for( int i = 0; i < ss1.size() ; i++ )
        cout<<ss1[i];
    cout<<endl;
    // 方法二：正向迭代器
    string::iterator iter = ss1.begin();
    for( ; iter < ss1.end() ; iter++)
        cout<<*iter;
    cout<<endl;
    // 方法三：反向迭代器
    string::reverse_iterator riter = ss1.rbegin();
    for( ; riter < ss1.rend() ; riter++)
        cout<<*riter;
    cout<<endl;

//string的删除：erase()方法
    //1. iterator erase(iterator p);//删除字符串中p所指的字符
    //2. iterator erase(iterator first, iterator last);//删除字符串中迭代器区间[first,last)上所有字符
    //3. string& erase(size_t pos = 0, size_t len = npos);//删除字符串中从索引位置pos开始的len个字符
    //4. void clear();//删除字符串中所有字符

//实例：
    string sss1 = "123456789";
    // sss1.erase(s1.begin()+1);              // 结果：13456789
    // sss1.erase(s1.begin()+1,s1.end()-2);   // 结果：189
    // sss1.erase(1,6);                       // 结果：189
    // sss1.claer();                          // 结果：啥也没有了

//string的字符替换：
    //1. string& replace(size_t pos, size_t n, const char *s);      //将当前字符串从pos索引开始的n个字符
    //替换成字符串s
    //2. string& replace(size_t pos, size_t n, size_t n1, char c);  //将当前字符串从pos索引开始的n个字符
    //替换成n1个字符c
    //3. string& replace(iterator i1, iterator i2, const char* s);  //将当前字符串[i1,i2)区间中的字符串替换为字符串s

//实例：
    string s_1("hello,world!");
    cout<<s_1.size()<<endl;                             // 结果：12
    s_1.replace(s_1.size()-1,1,1,'.');                  // 结果：hello,world.
    cout<<s_1<<endl;
    s_1.replace(6,5,"girl");// 这里的6表示下标  5表示长度 // 结果：hello,girl.
    cout<<s_1<<endl;
    // s1.begin(),s1.begin()+5 是左闭右开区间
    s_1.replace(s_1.begin(),s_1.begin()+5,"boy");       // 结果：boy,girl.
    cout<<s_1<<endl;

//string的查找：
    //1. size_t find (constchar* s, size_t pos = 0) const;
    //在当前字符串的pos索引位置开始，查找子串s，返回找到的位置索引，-1表示查找不到子串
    //2. size_t find (charc, size_t pos = 0) const;
    //在当前字符串的pos索引位置开始，查找字符c，返回找到的位置索引，-1表示查找不到字符
    //3. size_t rfind (constchar* s, size_t pos = npos) const;
    //在当前字符串的pos索引位置开始，反向查找子串s，返回找到的位置索引，-1表示查找不到子串
    //4. size_t rfind (charc, size_t pos = npos) const;
    //在当前字符串的pos索引位置开始，反向查找字符c，返回找到的位置索引，-1表示查找不到字符
    //5. size_t find_first_of (const char* s, size_t pos = 0) const;
    //在当前字符串的pos索引位置开始，查找子串s的字符，返回找到的位置索引，-1表示查找不到字符
    //6. size_t find_first_not_of (const char* s, size_t pos = 0) const;
    //在当前字符串的pos索引位置开始，查找第一个不位于子串s的字符，返回找到的位置索引，-1表示查找不到字符
    //7. size_t find_last_of (const char* s, size_t pos = npos) const;
    //在当前字符串的pos索引位置开始，查找最后一个位于子串s的字符，返回找到的位置索引，-1表示查找不到字符
    //8. size_t find_last_not_of (const char* s, size_t pos = npos) const;
    //在当前字符串的pos索引位置开始，查找最后一个不位于子串s的字符，返回找到的位置索引，-1表示查找不到子串

//实例：
    string sl("dog bird chicken bird cat");
    //字符串查找-----找到后返回首字母在字符串中的下标
    // 1. 查找一个字符串
    cout << sl.find("chicken") << endl;        // 结果是：9
    // 2. 从下标为6开始找字符'i'，返回找到的第一个i的下标
    cout << sl.find('i',6) << endl;            // 结果是：11
    // 3. 从字符串的末尾开始查找字符串，返回的还是首字母在字符串中的下标
    cout << sl.rfind("chicken") << endl;       // 结果是：9
    // 4. 从字符串的末尾开始查找字符
    cout << sl.rfind('i') << endl;             // 结果是：18-------因为是从末尾开始查找，所以返回第一次找到的字符
    // 5. 在该字符串中查找第一个属于字符串s的字符
    cout << sl.find_first_of("13br98") << endl;  // 结果是：4---b
    // 6. 在该字符串中查找第一个不属于字符串s的字符------先匹配dog，然后bird匹配不到，所以打印4
    cout << sl.find_first_not_of("hello dog 2006") << endl; // 结果是：4
    cout << sl.find_first_not_of("dog bird 2006") << endl;  // 结果是：9
    // 7. 在该字符串最后中查找第一个属于字符串s的字符
    cout << sl.find_last_of("13r98") << endl;               // 结果是：19
    // 8. 在该字符串最后中查找第一个不属于字符串s的字符------先匹配t--a---c，然后空格匹配不到，所以打印21
    cout << sl.find_last_not_of("teac") << endl;            // 结果是：21

//string的排序：sort(s.begin(),s.end())
    string sr = "cdefba";
    sort(sr.begin(),sr.end());
    cout<<"sr:"<<sr<<endl;     // 结果：abcdef

//string数组的排序:
    vector<string> disord_order(5);
    disord_order[0]="aaa",disord_order[1]="aaab",disord_order[2]="b",disord_order[3]="aac";
    disord_order[4]="aaac";
    sort(disord_order.begin(),disord_order.end());//升序
    for(int i=0;i<5;i++)
    cout<<disord_order[i]<<endl;
    sort(disord_order.begin(),disord_order.end(),greater<string>());//降序
    for(int i=0;i<5;i++)
    cout<<disord_order[i]<<endl;

//string的分割/截取字符串：strtok() & substr()
    //char str[30] = "litianyi@hust.edu@cn";
	//char seps[] = ".@";
	//char* s1 = NULL;
	//第一次调用时strtok函数找到@符号，将@符号改为'\0',记录位置，
	//下次调用时strtok函数从'\0'处开始向后切割字符串，所以之后调用传递NULL即可
    char str[] = "I,am,a,student; hello world!";
    const char *split = ",; !";
    char *p2 = strtok(str,split);
    while( p2 != NULL )
    {
        cout<<p2<<endl;
        p2 = strtok(NULL,split);
    }
    string ls1("0123456789");
    string ls2 = ls1.substr(2,5); // 结果：23456-----参数5表示：截取的字符串的长度,2表示下标
    cout<<ls2<<endl;

//注意，获取字符串的副本的误区：
    char animal[]="fox";
    char *ps=new char[strlen(animal)+1];
    //此时不能写ps=animal，这会使得新分配的内存失去唯一的使用途径，即ps本来指向分配的内存的地址，现在却被animal的地址覆盖
    //应该这样
    strcpy(ps,animal);
    //或者用string类，直接string animal_2(animal);
}