/*2022年11月30日11:18:46*/
#include "string_.h"
#include <iostream>
using namespace std;
int main(void)
{
	string_ s1(" and i am a c++ student. ");
	string_ s2="please enter your name ";
	string_ s3;
	cout << s2;//测试重载操作符<<,>>,+
	cin >> s3;
	s2 = "my name is " + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	cout << s2[0]<<endl;//
	s2.string_upper();
	cout << "the string \n" << s2 << "\ncontains " << s2.string_char_appear_nums('A')
		<< "'A' characters in it\n";
	s1 = "red";//先创建一个临时对象在赋给s1
	string_ rgb[3]={string_(s1),string_("green"),string_("blue")};
	cout << "enter the name of a primary color for mixing light: ";
	string_ ans;
	bool succ = false;
	while (cin >> ans)
	{
		ans.string_lower();
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i])//测试重载==
			{
				cout << "that's right!\n";
				succ = true;
				break;
			}
		}
		if (succ)
		break;
		else
			cout << "try again!\n";
	}
	cout << "bye\n";
	
}