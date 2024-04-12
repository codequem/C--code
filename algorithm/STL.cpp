//2022年12月13日18:32:03
//STL序列式容器

#include <iostream>
#include <array>//数组容器的头文件
#include <vector>//向量（动态数组）容器的头文件
#include <deque>//双端队列容器的头文件
#include <list>//双向链表容器的头文件
#include <forward_list>//单向链表容器的头文件
#include <map>//map,multimap容器的头文件
#include <set>//set,multiset容器的头文件
#include <unordered_map>//unordered_map,unordered_multimap容器的头文件
#include <unordered_set>//unordered_set,unordered_multiset容器的头文件
#include <stack>//stack适配器的头文件
#include <queue>//queue,priority_queue适配器的头文件
#include <utility>//pair的头文件
#include <algorithm>//remove是STL通用算法，要使用remove得加上这个头文件
#include <iterator>//要想使用distance函数要包含这个头文件
#include <string>//鼠鼠想要用string捏
#include <windows.h>//让控制台多停一会

using namespace std;

int main (void)
{
    //STL序列式容器：
    //array<T,N> 数组容器，T：typename  N：nums 
    array<int,100> arr1;//第二项必须是常量，不能是变量，因为array容器的大小是不能够改变的
    array<int,10> arr2{};//这样可以将元素全部初始化为0
    //比较常规的类方法
    arr1.begin(),arr1.end();//返回指向容器中第一个元素/最后一个元素后面的一个位置的随机访问迭代器
    arr1.rbegin(),arr1.rend();//(r:reverse)返回指向最后一个元素/第一个元素之前一个位置的随机访问迭代器
    arr1.cbegin(),arr1.cend(),arr1.crbegin(),arr1.crend();//给这些迭代器附加const属性，不能用于修改元素
    arr1.front(),arr1.back();//返回容器中第一个/最后一个元素的直接引用，该函数不适用于空的 array 容器。
    arr1.size();//返回容器中当前元素的数量，其值始终等于初始化 array 类的第二个模板参数 N
    arr1.max_size();//返回容器可容纳元素的最大数量，其值始终等于初始化 array 类的第二个模板参数 N
    arr1.empty();//判断容器是否为空
    //以下是个人觉得实用的类方法：
    arr1.at(1);//返回容器中 n 位置处元素的引用，该函数自动检查 n 是否在有效的范围内，如果不是则抛出异常。
    arr1.data();//返回一个指向容器首个元素的指针。利用该指针，可实现复制容器中所有元素等类似功能
    arr2.fill(1);//将括号中这个值赋值给容器中的每个元素。
    array<int,100> arr3;
    arr1.swap(arr3);//交换arr1和arr3容器中的所有元素，前提是这两个容器有相同的长度和类型
    get<3/*这里只能是常数*/>(arr1);//该重载函数的功能是访问容器中指定的元素，并返回该元素的引用,将访问arr1里的第三个元素
    /* if(!arr2.empty())
    {
        for(auto i=arr2.begin();i!=arr2.end();i++)//这里的auto可以让编译器自动判定变量的类型，就不用写成 
        //array<int,10>::iterator i;注意auto变量必须在声明时初始化，auto关键字的其他细节以后再探索吧
        cout<<*i<<endl;
    } */


    //vector<T> 向量（动态数组），T：typename
    vector<int> vec0;//这是一个空的vector容器
    vector<int> vec1{10};//1个int，初始化为10
    vector<int> vec2(10);//10个int，默认都是0
    vector<int> vec3(10,2);//10个int，初始化为2，这里的10和2都可以是变量
    vector<int> vec4(vec3);//复制了一整个vec3
    vector<int> vec5(vec3.begin(),vec3.begin()+3);//复制了vec3中前三个元素构成的容器
    vector<vector<int>> vec6(10,vector<int>(3));//十个vector<int>,初始化为vector<int>(3)
    //实际构造了一个储存了int[10][3]的vector容器

    //有意思的类方法（常规的和array容器一致）
    vec0.resize(10);//改变实际元素的个数(这里改成了10个)
    vec0.capacity();//返回当前容量
    vec0.reserve(20);//reserve（保留）容量小于20则扩容到20，否则什么也不做
    vec0.shrink_to_fit();//将内存减少到等于当前元素实际所使用的大小
    vec0.assign(10,5);//assign（指定/分配）//这是第一种用法，用10个int 5替换掉vec0原来的东西
    vec0.assign(vec2.begin(),vec2.begin()+3);//将括号内指定范围的元素替换vec0原来的东西
    vec0.pop_back();//移出序列尾部的元素,
    vec0.push_back(10);//在序列的尾部添加一个元素
    vec0.insert(vec0.begin(),10);//insert（插入）//第一种用法：在指定位置前插入一个元素，这里是在vec0[0]前插入了一个int 10
    vec0.insert(vec0.begin(),3,12);//这是在vec0的开头前面插入三个十二
    vec0.insert(vec0.begin(),vec5.begin(),vec5.end());//这是在vec0的开头前面插入整个vec5
    vec0.insert(vec0.begin(),{1,2,3,4});//这是把初始化列表（就是整个大括号）中所有元素插在给定位置之前
    //这四个函数都返回表示第一个新插入元素位置的迭代器
    vec0.erase(vec0.begin());//erase（删除）//这是第一种用法，只删除一个元素
    /* vector<int>::iterator itr = v.begin();
    while (itr!=v.end())
    {
        if (*v==1)
        {
            v.erase(itr);//删除一个元素之后，迭代器已经指向了被删除元素的下一个元素，再进行itr++会出现野指针
        }
        //在进行单个元素删除后，传入的迭代器指向不变，仍然指向被删除元素的位置
        //而被删除元素之后的所有元素都向前移动一位，也就是该迭代器实际上是指向了原来被删除元素的下一个元素
        itr++;//所以这里删除后迭代器会更新出错
    } */
    vec0.erase(vec0.begin(),vec0.begin()+3);//第二种用法，删除一个范围内的所有元素
    vector<int> (vec0).swap(vec0);//这里swap,用法就是交换任意两个vector容器，而vec0的大小（实际使用空间）和容量（预留了一部分空间）是不一样的
    //容量是大于大小的，而上述技巧可以压缩内存，使得vec0中没有多于的空间
    vec0.emplace(vec0.begin(),10);//在指定位置之前直接生成“一个”元素，每次只能插入一个元素，这是和insert的区别，但是这个函数更加快
    vec0.emplace_back(10);//在尾部生成“一个”元素，和insert效果一样，但是效率更高、
    remove(vec0.begin(),vec0.end(),10);
    for(auto i=vec0.begin();i!=vec0.end();i++)
    cout<<*i<<endl;//这里输出的数据是还有10的
    /* auto j=remove(vec0.begin(),vec0.end(),10);
    for(auto i=vec0.begin();i!=j;i++)
    cout<<*i<<endl;//这里输出的数据就没有10 */
    //vector中erase的作用是删除掉某个位置position或一段区域（begin, end)中的元素
    //减少其size，返回被删除元素下一个元素的位置。
    //vector中remove的作用是将范围内为val的值都remove到后面，返回新的end()值（非val部分的end）
    //但传入的原vector的end并没有发生改变，因此size也就没有变化
    //所以remove只是把这些值移到了我们访问不到（前提是自己更新了end迭代器）的地方
    
    //配合使用remove和erase就可以删掉这些全部
    vec0.erase(remove(vec0.begin(),vec0.end(),10),vec0.end());
    //很有意思

    vec0.clear();//清除所有元素，容器大小变成零
    //注：因为vector容器会自动分配内存，所以它的地址是不断变化的，因此要使用迭代器时，应当随手重新初始化


    //deque<T> 双端队列容器, T:typename
    //deque有vector的全部性质，并且deque还擅长在序列头部添加或删除元素，所耗费的时间复杂度也为常数阶O(1)
    //并且更重要的一点是，deque 容器中存储元素并不能保证所有元素都存储到连续的内存空间中
    //不要尝试用指针去访问deque指定位置的元素,但是可以用迭代器函数去遍历某个区间的元素
    //在deque中增加，删除元素只能利用提供的函数
    deque<int> deq0;//这是一个空的vector容器
    deque<int> deq1{10};//1个int，初始化为10
    deque<int> deq2(10);//10个int，默认都是0
    deque<int> deq3(10,2);//10个int，初始化为2，这里的10和2都可以是变量
    deque<int> deq4(deq3);//复制了一整个vec3
    deque<int> deq5(vec3.begin(),vec3.begin()+3);//复制了（其他容器中指定区域内的元素）vec3中前三个元素构成的容器
    //有意思的类方法（常规的和array,vector容器一致）
    deq1.push_back(15);//尾端添加一个新元素'15'
    deq1.push_front(15);//首端添加一个新元素'15'
    deq1.pop_back();//尾端删除一个元素
    deq1.pop_front();//首端删除一个元素
    deq1.emplace_back(15);//尾端生成一个元素//可代替push_back
    deq1.emplace_front(15);//首端生成一个元素//可代替push_front
    deq1.insert(deq1.begin(),12);//插入一个元素//更详细的在上面vector那里
    deq1.emplace(deq1.begin(),12);//直接生成一个元素//可代替insert//更详细的在上面vector那里
    deq1.erase(deq1.begin());
    //对于空的deque容器，可以通过push_back，push_front来往里面添加元素，但是不能通过迭代器
    //比如auto first=deque1.begin(),*first=1;//这样是错的，因为容器不会自动分配内存
    //除此之外，当向 deque 容器添加元素时，deque 容器会申请更多的内存空间
    //同时其包含的所有元素可能会被复制或移动到新的内存地址（原来占用的内存会释放），这会导致之前创建的迭代器失效。

    //访问方式与vector，array一致
    deq1[1]=5;
    deq1.front();//队首元素
    deq1.back();//队尾元素


    //list<T> 双向链表容器, T:typename
    //不能随机访问list中的元素，可以从首尾遍历访问
    //里面配备的不再是随机访问迭代器，而是双向迭代器，不能进行下标访问，迭代器之间不允许使用+=i运算符，<,>=之类的比较符
    //但是可以支持!=运算符
    //注意使用迭代器应该在元素的插入删除后及时更新，
    list<int> lis0;//这是一个空的list容器
    list<int> lis1{10};//1个int，初始化为10
    list<int> lis2(10);//10个int，默认都是0
    list<int> lis3(10,2);//10个int，初始化为2，这里的10和2都可以是变量
    list<int> lis4(lis3);//复制了一整个lis3
    list<int> lis5(lis3.begin(),lis3.end());//复制了lis3中前三个元素构成的容器
    list<int> lis6(vec3.begin(),vec3.begin()+3);//复制了vec3中前三个元素构成的容器,这种构造方式是不限制容器类型的
    //有意思的类方法
    lis3.splice(lis3.begin(),lis2);//splice（接合）,有三种形式
    //void splice (iterator position, list& x);将x中的所有元素全部移动到当前 list 容器中 position 指明的位置处。
    //void splice (iterator position, list& x, iterator i);将 x 容器中 i 指向的元素移动到当前容器中 position 指明的位置处。
    //void splice (iterator position, list& x, iterator first, iterator last);
    //将 x 容器 [first, last) 范围内所有的元素移动到当前容器 position 指明的位置处。
    //无论哪种方式，插入之后x的那部分元素都将从x中消失 
    lis3.erase(lis3.begin(),lis3.begin()++);//erase是按照位置去删除元素的
    lis3.remove(2);//remove是按照值删除的元素，删除lis3里面所有值为2的元素
    //lis3.remove_if();//传入一个函数给他，删除所有可以让这个函数返回非零值的元素，这个函数不限制参数个数
    lis3.unique();//这玩意可以去除list容器中相邻重复的元素，仅保留一份
    //有两种形式，一种就是上面这个不带任何参数，一种是传入一个返回bool值的二参数函数，也就是自定义去重规则
    //lis3.merge();//合并两个有着相同排序规则的容器
    lis3.sort();//排序
    lis3.reverse();//反转容器中元素的顺序

 
    //forward_list<T> 单向链表容器, T:typename 相比于list容器，效率更高
    forward_list<int> flis0;//这是一个空的forward_list容器
    forward_list<int> flis1{10};//1个int，初始化为10
    forward_list<int> flis2(10);//10个int，默认都是0
    forward_list<int> flis3(10,2);//10个int，初始化为2，这里的10和2都可以是变量
    forward_list<int> flis4(flis3);//复制了一整个flis3
    forward_list<int> flis5(flis3.begin(),flis3.end());//复制了flis3中前三个元素构成的容器
    forward_list<int> flis6(vec3.begin(),vec3.begin()+3);//复制了vec3中前三个元素构成的容器,这种构造方式是不限制容器类型的
    //有意思的类方法 因为是单链表，所以只能使用前向迭代器，不支持在在尾部增删，支持在头部增删
    flis3.before_begin();//返回一个前向迭代器，其指向容器中第一个元素之前的位置。
    flis3.push_front(10);//函数功能就和名字一样
    flis3.pop_front();//函数功能就和名字一样
    flis3.emplace_front();//函数功能就和名字一样
    flis3.emplace_after(flis3.begin(),10);//在指定位置之后生成一个元素
    flis3.insert_after(flis3.begin(),10);//在指定位置之后插入一个元素
    //可以通过以下方法来确定容器中元素个数，注：forward_list中没有提供size函数
    int count=distance(flis3.begin(),flis3.end());
    //可以通过advance函数来让这个前向迭代器一次向前进i格
    auto it=flis3.begin();
    advance(it,3);//相当于it++三回
    //总体上看就是他的方法相比于list容器有了after版本，尾端的一些操作没有了


    //STL关联式容器：(底层为红黑树)
    //pair<T,T> 键值对类模板 <key,value> T:typename
    pair<int,string> pair1;//默认构造方式，键为0，没有值
    pair<int,string> pair2(5,"hahaha");
    pair<int,string> pair3(pair2);
    pair<int,string> pair4(make_pair(4,"cyf"));
    //这个构造的原理是，make_pair生成一个pair对象
    //这个临时对象最为返回值然后又成了构造函数的参数，这里调用的是移动构造函数[目前我还没学到]，而不是复制构造函数
    //这种方式等价于：pair<int,string> pair4=make_pair(4,"cyf");
    pair<string,string> pair5(string("wiehid"),string("shfjdh"));
    cout << "pair1: " << pair1.first << " " << pair1.second << endl;
    cout << "pair2: " << pair2.first << " " << pair2.second << endl;
    cout << "pair3: " << pair3.first << " " << pair3.second << endl;
    cout << "pair4: " << pair4.first << " " << pair4.second << endl;
    cout << "pair5: " << pair5.first << " " << pair5.second << endl;
    //咱还可以手动赋值
    pair1.first=1;
    //pair里重载了<,>之类的比较运算符，规则是先比键，再比值，注意：如果两个pair要相比，他们的键值类型必须对应相等
    //它还有一个swap成员函数，如果两个pair要交换，他们的键值类型必须对应相等
    pair4.swap(pair3);


    //map<K,T> map 容器存储的都是 pair<const K,T>对象 K:key T:type
    //map 容器配备的是双向迭代器,这意味着，map 容器迭代器只能进行 ++p、p++、--p、p--、*p 操作
    //并且迭代器之间只能使用 == 或者 != 运算符进行比较
    //在使用 map 容器存储多个键值对时，该容器会自动根据各键值对的键的大小，按照既定的规则进行排序。
    //默认情况下，map 容器选用std::less<T>排序规则,会根据键的大小对所有键值对做升序排序
    //另外需要注意的是，使用 map 容器存储的各个键值对，键的值既不能重复也不能被修改。
    //换句话说，map 容器中存储的各个键值对不仅键的值独一无二，键的类型也会用 const 修饰
    //这意味着只要键值对被存储到 map 容器中，其键的值将不能再做任何修改。
    //map 容器的模板定义如下：
    /* template < class Key,                                     // 指定键（key）的类型
                  class T,                                       // 指定值（value）的类型
                  class Compare = less<Key>,                     // 指定排序规则,有默认值
                  class Alloc = allocator<pair<const Key,T> >    // 指定分配器对象的类型，有默认值
                > class map; */
    map<int,string> map1;//默认构造方式，键为0，没有值，初始状态下为空
    map<int,string> map2{{3,"vyf"},{4,"hahah"}};//map2初始状态下包含两个键值对，且进行了初始化
    //map 容器中存储的键值对，其本质都是 pair 类模板创建的 pair 对象，所以下面语句等效于上面语句
    map<int,string> map3{make_pair(3,"vdhf"),make_pair(4,"jahah")};
    map<int,string> map4(map3);//利用赋值构造函数，构造了一个与map3完全相同的容器map4
    map<int,string> map5(++map4.begin(),map4.end());//map 类模板还支持取已建map容器中指定区域内的键值对，创建并初始化新的map容器
    map<int,string,greater<int>> map6{{3,"vyf"},{4,"hahah"}};//这是更改了键的排序规则

    //有趣的类方法：
    map3.begin();//返回指向容器中第一个（注意，是已排好序的第一个）键值对的双向迭代器
    map3.end();//返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器
    map3.find(5);//在 map 容器中查找键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器
    //反之，则返回和 end() 方法一样的迭代器。
    //以下三个方法多用于mutimap容器中
    map3.lower_bound(3);//不小于key//返回一个指向当前 map 容器中第一个大于或等于 key 的键值对的双向迭代器。
    map3.upper_bound(4);//大于key//返回一个指向当前 map 容器中第一个大于 key 的键值对的迭代器。
    pair<map<int,string>::iterator,map<int,string>::iterator>receive=map3.equal_range(4);
    //该方法返回一个 pair 对象（包含2个双向迭代器）,注意接收返回值的pair的元素类型
    //其中 pair.first和 lower_bound()方法的返回值等价，pair.second和 upper_bound()方法的返回值等价。
    //也就是说，该方法将返回一个范围，该范围中包含的键为key的键值对（map容器键值对唯一，因此该范围最多包含一个键值对）
    //当然这玩意运用于mutimap中，返回的范围中，所有的键值对的键都为key
    map3.erase(3);//参数可以是key,也可以是一个指向键值对的迭代器，也可以是一个由两个迭代器指定的范围
    //但是要注意在循环中的使用，以下代码是错误的
    /* for(auto iter=mapTest.begin();iter!=mapTest.end();++iter)  
    {  
        cout<<iter->first<<":"<<iter->second<<endl;  
        mapTest.erase(iter);//这里iter指向的键值对被删除了，iter也失效了，所以++iter是无效的
    }*/
    //应改写为如下形式
    /* for(auto iter=mapTest.begin();iter!=mapTest.end();)//注意此处不能再写iter++  
    {  
        cout<<iter->first<<":"<<iter->second<<endl;  
        mapTest.erase(iter++);//后缀++既能让iter被删之前就指向下一位，又能返回原来的位置让erase去删
    } */
    map3.swap(map2);//交换2个map容器中存储的键值对
    map3.count(3);//在当前map容器中，查找键为key的键值对的个数并返回
    //注意，由于map容器中各键值对的键的值是唯一的,因此该函数的返回值最大为1
    //map3.insert({6,"qwqw"});
    map3.insert(make_pair(6,"qwqw"));//向 map 容器中插入键值对。//pair<iterator,bool> insert (const value_type& val);
    //注意这个方法会返回一个pair，bool代表是否成功插入，iterator指向新插入的val(如果成功)，或者指向原本容器中就有的键为key的键值对(如果失败)
    //当然也可以插入一个范围 void insert (InputIterator first, InputIterator last);
    map3.emplace(5,"sldfkd");//在map容器中直接构造新的键值对
    cout<<map3.size()<<endl;//返回当前 map 容器中存有键值对的个数
    //map3.emplace_hint();//与emplace相比，这个函数还要指定位置，但是没啥用，map还是会自动排序的
    map3.at(4);//这个方法也是通过键查找值，但是如果查找失败，该方法不会向容器中添加新的键值对，而是直接抛出 out_of_range。
    map3[3];//value=map[key],这个方法使得通过键获取值非常简单，但是当这个key在map中不存在时，将会向map容器中添加一个键值对
    //这个键值对以[]中的为键，值为0或""(空字符串)
    //这个方法还可以修改指定键对应的键值对中的值
    for(auto i=map3.begin();i!=map3.end();i++)
    cout<<i->first<<' '<<i->second<<endl;//first为键，second为值
    map3.clear();//清空 map 容器中所有的键值对
    cout<<map3.empty()<<endl;//若容器为空，则返回true,否则false


    //multimap<K,T> 容器存储的都是 pair<const K,T>对象 K:key T:type
    //multimap别的都和map容器完全一致，但是有一点不同，multimap允许容器中存在多个键相同的键值对
    //和 map 容器相比，multimap 未提供 at() 成员方法，也没有重载 [] 运算符，因为一个键不一定对应一个键值对嘛
    //multimap可存储多个具有相同键的键值对，因此lower_bound()、upper_bound()、equal_range()以及count()会经常用到
    //其他的成员方法都和map一样，使用方法也一样，所以不过多介绍了
    //下面来详细说一下如何自定义关联式容器的排序方法：
    /* 1）一般情况下，我们定义一个map是直接使用前两个参数的，也就是说我们一般都指定key和value的类型，
    没有指定Compare类的类型。所以默认情况(less<T>)下，key的类型必须能够进行<运算，且唯一，也就说关键字类型key必须严格弱序。
    2）当我们使用Compare类来自定义排序关键字类型key的时候，必须要保证“行为正常”的<运算符或>运算符。 */
    //首先，容器类的模板的第三个参数是以类的形式呈现的，先来看看默认的less<T>实现
    /* template <class T> struct less : binary_function <T,T,bool> 
    {  
        bool operator() (const T& x, const T& y) const  
        {return x<y;}  
    }; *///这玩意得在main函数外面写(因为template的原因)，以此类推，我们可以自定义一个按照key中的string长度排序，程序如下：
    struct cmp  //自定义比较规则
    {
	    bool operator() (const string& str1, const string& str2)
	    {
		    return str1.length() < str2.length(); //咱自己知道key的类型，没必要像库的写成模板
	    }
    };
    //按照这个示例，我们还可以设计其他的比较规则，把比较规则写在cmp结构中，然后在定义map的时候调用即可~
    //确切的说，是在cmp结构中重载()操作符
    //这下我们知道了如何自定义key的排序规则，那么我们能不能依据value排序呢？
    //显然由于map红黑树的底层数据结构，是不能依据value排序的，但是可以借助其他的容器来实现这个操作

    //map是个关联容器，不是序列容器。像是一些序列容器list, vector都是可以排序的~,所以：
    //首先，map中的<key, value>是pair形式的，那么我们就可以把一个pair作为vector中的元素；
    //然后，调用vetor容器中的sort函数，sort函数也是可以用户指定比较类型的
    /* bool compare(const pair<string,int>& a,const pair<string,int>& b)
    {
	    f(a.second==b.second)return a.first<b.first;
        else return a.second>b.second;
    };
    map<string,int> map7{{"a",1},{"b",2},{"c",3}};
    vector<pair<string,int>> v(m.begin(),m.end());//将map中的元素拷贝到vector中
    sort(v.begin(),v.end(),compare);//实现value的排序 */
    //至此，map的两种排序需求就都讲完啦


    //set<K,T> 容器存储的都是 pair<const K,T>对象 K:key T:type
    //使用 set 容器存储的各个键值对，要求键 key 和值 value 必须相等,set容器只能存储这样的pair数据
    //基于这种特性，当使用 set 容器存储键值对时，只需要为其提供各键值对中的 value 值(它帮你自动补上key值)
    //另外，使用 set 容器存储的各个元素的值必须各不相同。
    //更重要的是，从语法上讲 set 容器并没有强制对存储元素的类型做 const 修饰，即 set 容器中存储的元素的值是可以修改的。
    //对于初学者来说，切勿尝试直接修改 set 容器中已存储元素的值，这很有可能破坏 set 容器中元素的有序性
    //最正确的修改 set 容器中元素值的做法是：先删除该元素，然后再添加一个修改后的元素。

    set<string> set1;//默认构造函数，创建空的set容器
    set<string> set2{"hahahah","sjdlsdf","wuhu"};//给set初始化只需要给定value值就行，这样一次性可以往里面添加多个元素
    set<string> set3(set2);//复制构造函数,构造了一个和set2一模一样的set3,但是用这玩意得保证类型完全一致，排序规则也得一样
    set<string> set4(++set2.begin(),set2.end());//还支持取已有 set 容器中的部分元素，来初始化新 set 容器
    set<string,greater<string>> {"hahahah","sjdlsdf","wuhu"};

    //有意思的类方法
    //tnnd这家伙对比map没啥创新，唯一的创新是set容器类模板中未提供 at() 成员函数，也未对 [] 运算符进行重载
    //因此，要想访问 set 容器中存储的元素，只能借助 set 容器的迭代器。
    //且：C++ STL 标准库为 set 容器配置的迭代器类型为双向迭代器（悲）

    //multiset<K,T> 容器存储的都是 pair<const K,T>对象 K:key T:type
    //它和set的差别是multimap和map的差别


    //STL无序关联式容器：(底层为哈希表)
    //无序容器内部存储的键值对是无序的（这是和关联式容器唯一的差别），各键值对的存储位置取决于该键值对中的键，
    //和关联式容器相比，无序容器擅长通过指定键查找对应的值（平均时间复杂度为 O(1)）
    //但对于使用迭代器遍历容器中存储的元素，无序容器的执行效率则不如关联式容器
    //总的来说，实际场景中如果涉及大量遍历容器的操作，建议首选关联式容器
    //反之，如果更多的操作是通过键获取对应的值，则应首选无序容器。
    //unordered_map 容器迭代器的类型为前向迭代器（又称正向迭代器）（悲）。这意味着，假设 p 是一个前向迭代器，
    //则其只能进行 *p、p++、++p 操作，且 2 个前向迭代器之间只能用 == 和 != 运算符做比较。


    //unordered_map<K,T> unordered_map容器存储的都是 pair<const K,T>对象 K:key T:type
    //unordered_map 容器模板的定义如下所示：
    /*  template<   class Key,                        //键值对中键的类型
                    class T,                          //键值对中值的类型
                    class Hash = hash<Key>,           //容器内部存储键值对所用的哈希函数
                    class Pred = equal_to<Key>,       //判断各个键值对键相同的规则
                    class Alloc = allocator< pair<const Key,T> >  // 指定分配器对象的类型
                >   class unordered_map; */
    //当无序容器中存储键值对的键为自定义类型时，默认的哈希函数 hash 以及比较函数 equal_to 将不再适用
    //只能自己设计适用该类型的哈希函数和比较函数，并显式传递给 Hash 参数和 Pred 参数
    unordered_map<int,string> umap1;//默认构造方式，键为0，没有值，初始状态下为空
    unordered_map<int,string> umap2{{3,"vyf"},{4,"hahah"}};//map2初始状态下包含两个键值对，且进行了初始化
    //unordered_map容器中存储的键值对，其本质都是 pair 类模板创建的 pair 对象，所以下面语句等效于上面语句
    unordered_map<int,string> umap3{make_pair(3,"vdhf"),make_pair(4,"jahah")};
    unordered_map<int,string> umap4(umap3);//利用赋值构造函数，构造了一个与umap3完全相同的容器umap4
    unordered_map<int,string> umap5(++umap4.begin(),umap4.end());
    //unordered_map类模板还支持取已建map容器中指定区域内的键值对，创建并初始化新的unordered_map容器
    //有意思的类方法：(类似于map的这里就没有写)
    /*需要注意的是，在操作 unordered_map 容器过程（尤其是向容器中添加新键值对）中，一旦当前容器的负载因子
    超过最大负载因子（默认值为 1.0），该容器就会适当增加桶的数量（通常是翻一倍），并自动执行 rehash() 成员方法，
    重新调整各个键值对的存储位置（此过程又称“重哈希”），此过程很可能导致之前创建的迭代器失效（所谓迭代器失效
    针对的是那些用于表示容器内某个范围的迭代器，由于重哈希会重新调整每个键值对的存储位置，所以容器重哈希之后，
    之前表示特定范围的迭代器很可能无法再正确表示该范围。但是，重哈希并不会影响那些指向单个键值对元素的迭代器）
    经测试，begin()/end() 和 cbegin()/cend() 迭代器对，重哈希并不影响这两对，整个遍历的操作仍然可以顺利完成。*/
    umap3.equal_range(3);//返回一个 pair对象,其包含2个迭代器，用于表明当前容器中键为key的键值对所在的范围，同理更适用于multiunordered_map
    //https://blog.51cto.com/u_13984132/5499613,下面这几个函数所需要的知识见这个博客
    umap3.bucket(3);//返回以 key 为键的键值对所在桶的编号。
    umap3.bucket_count();//返回当前容器底层存储键值对时，使用桶的数量。
    umap3.max_bucket_count();//返回当前系统中，unordered_map 容器底层最多可以使用多少个桶。
    umap3.bucket_size(umap3.bucket(3));//返回第 n 个桶中存储键值对的数量。
    umap3.load_factor();//返回 unordered_map 容器中当前的负载因子
    umap3.max_load_factor();//返回或者设置当前 unordered_map 容器的最大负载因子
    umap3.reserve(20);//将容器使用的桶数（bucket_count() 方法的返回值）设置为最适合存储 n 个元素的桶数
    umap3.rehash(20);//尝试重新调整桶的数量为等于或大于 n 的值。如果 n 大于当前容器使用的桶数，则该方法会是容器重新哈希
    //该容器新的桶数将等于或大于 n。反之，如果 n 的值小于当前容器使用的桶数，则调用此方法可能没有任何作用。
    umap3.key_eq();//返回用于比较键的相等性的函数
    umap3.hash_function();//返回当前容器使用的哈希函数对象。可以通过自带的hasher类型来使用
    //umap3.merge();//将一个unorderde_map中的元素合并到另一个unordered_map中，注意
    /*  p: [3] { {A, 1}, {B, 2}, {C, 3} }
        q: [3] { {A, 4}, {D, 5}, {E, 6} }
        p.merge(q);
        p: [5] { {E, 6}, {D, 5}, {A, 1}, {B, 2}, {C, 3} }
        q: [1] { {A, 4} }*///重复的将留在原容器中
    //umap3.extract();//照理来说map中的key是不能改变的，但是这个函数extract(提取)先将特定的键值对取出，然后就可以更改这个键值对中键的值


    //unordered_multimap<K,T> unordered_multimap容器存储的都是 pair<const K,T>对象 K:key T:type
    //它和unordered_map的区别就是map和mulitmap的区别，这里不再展开介绍该容器
    //同理unordered_set和unordered_mulitset这里也不再赘述了
    //下面讲讲如何自定义C++ STL无序容器的哈希函数和比较规则（估计和自定义排序规则是一样的）
    //https://www.cnblogs.com/lyxtech/articles/15224966.html,实际和自定义排序规则是一个东西


    //STL容器适配器：它以某种容器作为底层结构，改变其接口，使它符合该（容器适配器想转化成的）容器的特性。
    //stack<T,Container=deque<T>> 栈适配器，其中 T 为存储元素的类型，Container 表示底层容器的类型
    //没有迭代器，访问元素的唯一方式是遍历容器，通过不断移除访问过的元素，去访问下一个元素。
    stack<int> sta1;//创建一个不包含任何元素的 stack 适配器，并采用默认的 deque 基础容器：
    //通过指定第二个模板类型参数，我们可以使用出 deque 容器外的其它序列式容器，只要该容器支持 
    //empty()、size()、back()、push_back()、pop_back() 这 5 个成员函数即可。
    stack<int,list<int>> sta2;//一个使用 list 基础容器的 stack 适配器：
    //可以用一个基础容器来初始化 stack 适配器，只要该容器的类型和 stack 底层使用的基础容器类型相同即可
    deque<int> test{1,2,3};
    stack<int> sta3(test);
    //可以用一个 stack 适配器来初始化另一个 stack 适配器，只要它们存储的元素类型以及底层采用的基础容器类型相同即可
    stack<int> sta4(sta3);
    //它的成员函数非常简单，开心
    sta3.empty();//当 stack 栈中没有元素时，该成员函数返回 true；反之，返回 false。
    sta3.size();//返回 stack 栈中存储元素的个数。
    sta3.top();//返回一个栈顶元素的引用，类型为 T&。如果栈为空，程序会报错
    sta3.push(5);//将元素压入栈
    sta3.pop();//弹出栈顶元素
    sta3.emplace(6);//在栈中生成元素
    sta3.swap(sta4);//将两个 stack 适配器中的元素进行互换,这两个适配器了类型必须完全相同
    //开心，终于有栈玩了


    //queue<T,Container=deque<T>> 队列适配器，其中 T 为存储元素的类型，Container 表示底层容器的类型
    //没有迭代器，访问元素的唯一方式是遍历容器，通过不断移除访问过的元素，去访问下一个元素。
    //要想创建一个queue适配器，是和stack一样的
    //它的成员函数：
    queue<int> que1{1,2,3};
    /* que1.empty();
    que1.size(); */
    que1.front();//返回 queue 中第一个元素的引用
    que1.back();//返回 queue 中最后一个元素的引用
    /* que1.push();
    que1.emplace();
    que1.pop();
    que1.swap(); */


    //priority_queue<T,Container=vector<T>,Compare=less<T>> 优先队列适配器，其中 T 为存储元素的类型，Container 表示底层容器的类型
    //这种队列并不是先进先出，而是根据比较规则，优先级最大的先出
    priority_queue<int> pque1;//底层采用默认的 vector 容器，排序方式也采用默认的 std::less<T> 方法
    //可以使用普通数组或其它容器中指定范围内的数据，对 priority_queue 容器适配器进行初始化：
    int array_[5]={1,2,3,4,5};//用来初始化的数组或容器中的数据不需要有序，priority_queue 会自动对它们进行排序
    priority_queue<int> pque2(array_,array_+4);
    priority_queue pque3<int,deque<int>,greater<int>>(array_,array_+4);//当然我们还可以自定义排序规则
    //依然和上面map的自定义排序规则是一个语法
    //相比queue多了一个方法：
    pque2.top();//返回 priority_queue 中第一个元素的引用形式。


    //至此结束 终于
    system("pause");
    return 0;
}