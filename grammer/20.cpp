/*2022年11月10日23:42:30
名称空间*/

#include <iostream>

using namespace std;//using编译指令使得名称空间中的所有的名称都可用，这些名称可以使用的区域取决于此时using语句位于那个声明区域

namespace Jack{
    double pail;
    void fetch();
    int pal;
    namespace Jill{
        int hahah;//如果要使用这玩意，就需要Jack::Jill::hahah
        //或者使用using namespace Jack::Jill
        //或者using Jack::Jill::hahaha
    }
}//名称空间可以是全局的，也可以位于另一个名称空间中，但不能位于代码块中，在默认情况下
//在名称空间中声明的名称的连接性为外部的（除非它引用了常量）

//任何名称空间中的名称都不会与其他名称空间的名称发生冲突，名称空间中的声明和定义规则和全局变量一致

//名称空间是开放的，即可以把名称加入到已有的名称空间中:
namespace Jack{
    int sum(int);
}


//可以在名称空间中使用using编译指令和using声明
namespace Kate{
    using Jack::pail;
    //这时，pail在Kate这个名称空间中就叫pail
    //所以我们可以使用Jack::pail和Kate::pail来使用pail
    using Jack::sum;
    using namespace std;
    //using编译指令是可传递的，就像>操作符，若a>b,b>c则a>c
    //如果使用using namespace Kate,就相当于同时使用了using namespace std和using namespace Kate
}


//可以给名称空间创建别名：
namespace kt=Kate;//此时kt就是Kate的别名
//从而简化对嵌套名称空间的使用
namespace JJ=Jack::Jill;
using JJ::hahah;//就很方便
/* namespace Jack{
    double pail;
    void fetch();
    int pal;
    namespace Jill{
        int hahah;//如果要使用这玩意，就需要Jack::Jill::hahah
        //或者使用using namespace Jack::Jill
        //或者using Jack::Jill::hahaha
    }
}
 */


//可以通过省略名称空间的名称来创建未命名的名称空间
namespace{
    int ice;
    int bandycoot;
}
//对于这种名称空间，就像后面跟个一个using编译指令一样，从声明点到声明区域末尾都可用，从这个方面看，他们与全局变量相似
//但是由于他们没有名称，因此不能显式的使用using编译指令或者using声明来使它在其他位置都可用
//具体的说，不能在未命名名称空间所属文件之外的其他文件中使用该名称空间中的名称
//因此该方法可以代替链接性为内部的静态变量（应该说c++标准比起在去全局变量前面加static，更支持这么做）

int pail=1;
int main (void)
{
    //通过作用域解析操作符（：：）可以访问名称空间中的名称
    Jack::pail=0;//这种包含名称空间的名称叫做限定的名称
    int pail=2;//这样不会和名称空间的相同名称重复
    //但是如果使用using Jack pail后上面一条语句就会报错，因为重复定义了
    cout<<::pail;//这里使用的是全局变量pail
    cout<<pail;//这里使用的是局部变量pali
    cout<<Jack::pail;//这里使用的是名称空间中的pali
    //如果这里使用using Jack pail那么pail就被加入到了main（）所属的声明区域
    //如果在main()函数外面使用这条语句，那么pail就被加入到全局声明区域
    //这条语句声明的名称的使用区域取决于此时using位于什么声明区域，但是这些名称在这个区域中视为在区域外声明的
    //也就是说，using编译指令在函数中使用，那么这些名称只能在这个函数中使用，但是在这个函数中视为在外面声明的，在这个函数中不视为局部变量
}


//最重要的是要分清楚using编译指令和using声明的区别
//using声明指令就好像声明了相应的名称一样，如果某个名称已经在函数中声明了，就不可以再次使用using声明导入相同的名称
//然而，使用using编译指令时，将进行名称解析，如果有同名的局部名称，那么它将会隐藏名称空间名，但是和全局变量一样，可以用作用域解析操作符访问它

//也就是说，using编译指令导入所有名称，如果和局部名称发生冲突，则局部名称将覆盖名称空间版本，而且编译器不会发出警告
//但是using声明如果与局部名称发生冲突，编译器将发出警告
//因此using声明指令更加安全


//名称空间的有关指导意见：
//使用在已经命名的名称空间中声明的变量，而不是使用外部全局变量
//使用在已命名的名称空间中声明的变量，而不是使用静态全局变量
//如果开发了一个函数库或者类库，将其放在一个名称空间中
//仅将using编译指令作为一种将旧代码转换为使用名称空间的权宜之计
//不要在头文件中使用using编译指令，这样做会隐藏哪些名称可用，如果非要使用using，应当把他放在所有预处理器编译指令#Inlcude之后
//导入名称时首选使用作用域解析操作符或using声明的方法
//对于using声明，首选将其作用域设置为局部而不是全局