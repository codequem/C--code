#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int a = 9;
    const int *p = &a;
    double b = 10.9;
    const int &q = b; //这样则可以，它实际上的工作原理是
    /*{
        const int temp = b;
        const int &q = temp;//从这里我们也可以看出，原本的变量b是可以被修改的，而常值引用q因为绑定的是一个未命名的对象
        //所以不能被修改
    }*/
    // int &s =b; 这样是不被允许的
    a = 10;
    b = 12.9;

    cout << a << endl;
    cout << *p << endl;
    cout << b << endl;
    cout << q << endl;

    string str = "hello";
    for (auto &c : str) //范围for语句，c是一个引用，因此修改c就是修改str中的字符
    //这个for语句的工作原理是
    // c以此作为str这个列表中的所有元素的引用，也就是说这种for实际是对列表全体元素作处理
    {
        c = toupper(c);
        cout << c;
    }
    vector<int> vec = {1, 2, 3, 4, 5};
    auto vec_beg = vec.begin();
    decltype(vec.begin()) vec_end = vec.end();
    std::vector<int>::iterator vec_beg_ = vec.begin();
    return 0;
}