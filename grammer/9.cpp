/*2022年10月27日14:53:42
对矢量可执行的其他操作
for_each(),random_shuffle(),
find(),
sort(),stable_sort()
merge(),
upper_bound(),lower_bound(),equel_range(),binary_search()*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef struct review
{
    string title;
    int rating;
}review;

void showbooks(const review&rr);
void showint(const int &rr);
bool operator< (const review &r1,const review &r2);
bool grade_down (const int &r1,const int &r2);

int main (void)
{
    vector<review> books(3);
    vector<review>::iterator pb,pbb;
    vector<int> answers;
    vector<int> array(10);
    vector<int> ar_nums={2,4,6,4,7};
    vector<int>::iterator pi,pii;
    for(pi=array.begin();pi!=array.end();pi++)
    cin>>*pi;
    /* for(pb=books.begin();pb!=books.end();pb++)
    cin>>(*pb).title>>(*pb).rating; */


    for_each(array.begin(),array.end(),showint);
    /* for_each(books.begin(),books.end(),showbooks); */
    //for_each函数接受三个参数，前两个是定义容器中区间的迭代器，
    //最后一个是指向函数的指针，for_each函数将被指向的函数应用于容器区间中的各个元素，被指向的函数不能修改容器元素的值
    
    
    random_shuffle(array.begin(),array.end());
    //random_shuffle接受两个指定区间的迭代器参数,并随机排列该区间中的元素
    //该函数要求容器支持随机访问
    for_each(array.begin(),array.end(),showint);
    
    
    sort(array.begin(),array.end());
    //这里可以直接使用<functional>中定义的两个结构greater和less
    //用法如下：
    sort(array.begin(),array.end(),greater<int>());//从大到小
    sort(array.begin(),array.end(),less<int>());//从小到大
    for_each(array.begin(),array.end(),showint);
    //sort函数有两个版本，这是第一个版本，它接受两个定义区间的迭代器参数，并使用为储存在容器中的类型元素定义的<操作符，对区间中的值进行比较，
    //此时是按升序排列的（从小到大）
    //sort函数的第二个版本如下：
    //第二个版本的第一种形式：
    //当容器元素是用户定义的对象时对他们进行排序
    //使用之前必须定义能够处理该类型对象的operator<()函数，按升序排序
    //这个版本的这种形式在定义好能够处理该类型对象的operator<()函数后，就与第一个版本的使用无异
    /* sort(books.begin(),books.end()); */
    //第二种形式可以按降序排序或者按自定的规则排序
    //使用方法如下：
    sort(array.begin(),array.end(),grade_down);
    sort(ar_nums.begin(),ar_nums.end(),grade_down);
    //前两个参数和第一种版本一样，第三个参数是指向要使用的函数的指针（函数对象）
    //这个自定义的函数返回值可转换为bool，false表示两个参数的顺序不正确
    for_each(array.begin(),array.end(),showint);
    
    
    stable_sort(array.begin(),array.end(),grade_down);
    //stable_sort函数既可以完成排序又可以保证相等元素的相对位置
    //语法和sort函数完全一致
    
    /* for_each(books.begin(),books.end(),showbooks); */


    //merge()函数接受五个（或者六个参数）,前两个参数是第一个容器的范围，后两个是第二个容器的范围
    //当省略第六个参数时，两个容器中的元素必须符合升序排列，容器元素必须支持<(同sort)
    //当使用第六个参数时，这个参数实际上是提供了容器中排序的规则，我们提供的两个容器必须事先符合这个规则
    //第五个参数是将两个容器合并后储存的容器，这个容器必须要事先分配元素数量
    answers.resize(15);
    merge(ar_nums.begin(),ar_nums.end(),array.begin(),array.end(),answers.begin(),grade_down);
    for_each(answers.begin(),answers.end(),showint);


    pii=find(answers.begin(),answers.end(),3);
    //find函数接受三个参数，前两个是被查找的容器的范围，最后一个是要搜索的元素
    //find函数返回一个迭代器，这个迭代器指向查找到的第一个目标元素
    //底层原理是顺序查找


    sort(array.begin(),array.end());
    sort(ar_nums.begin(),ar_nums.end());
    //以下四个查找函数的底层原理都是二分查找
    lower_bound(answers.begin(),answers.end(),3);
    //lower_bound()函数在指定区域内查找“不小于”目标值的第一个元素
    //底层原理是二分查找，所以被搜索的容器必须事先按升序排列（不含第四个参数的版本）
    //第四个参数是自定义的查找规则，同理，被搜索的容器必须事先按此规则排列
    //再次强调，该函数仅适用于已排好序的序列。所谓“已排好序”
    //指的是 [first, last) 区域内所有令 element<val（或者 comp(element,val)
    //comp 用于指定比较规则，此参数可接收一个包含 2 个形参（第二个形参值始终为 val）且返回值为 bool的函数
    //其中 element 为指定范围内的元素）成立的元素都位于不成立元素的前面。
    //返回一个迭代器，这个迭代器指向查找到的第一个目标元素
    upper_bound(answers.begin(),answers.end(),3);
    //同lower，只是查找（返回）的是第一个大于给定元素的元素的位置
    equal_range(answers.begin(),answers.end(),3);
    //同lower，但是查找的是等于目标值的所有元素
    //该函数会返回一个 pair 类型值，其包含 2 个正向迭代器。当查找成功时：
    //第 1 个迭代器指向的是 [first, last) 区域中第一个等于 val 的元素；
    //第 2 个迭代器指向的是 [first, last) 区域中第一个大于 val 的元素。
    //反之如果查找失败，则这 2 个迭代器要么都指向大于 val 的第一个元素（如果有），要么都和 last 迭代器指向相同。
    binary_search(answers.begin(),answers.end(),3);
    //同lower，返回在给定范围内是否有目标值（bool）


    return 0;
}

void showint(const int &rr)
{//打印整个容器中的元素
    cout<<rr<<endl;
}

void showbooks(const review&rr)
{
    cout<<rr.rating<<endl<<rr.title<<endl;
}

bool operator< (const review &r1,const review &r2)
{//为review这个用户定义的对象（review）定义能够处理该类型对象的operator<()函数
    if(r1.title<r2.title)
    return true;
    else if(r1.title==r2.title&&r1.rating<r2.rating)
    return true;
    else return false;
}


//这里可以直接使用<functional>中定义的两个结构greater 和less
bool grade_down (const int &r1,const int &r2)
{//r1>r2,也就是前面的大于后面的，即降序排列
    if(r1>=r2)
    return true;//即如果前面的大于后面的，说明顺序正确
    else return false;
    //否则顺序不正确
}
/* 简单说来就是：
比较a和b，如果是想升序，那么就定义当a<b的时候返回true（即前一个小于后面一个”升序“）
如果是想降序，那么就定义当a>b的时候返回true */