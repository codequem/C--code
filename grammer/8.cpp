/*2022年10月27日00:05:27
vector(矢量)模板类，迭代器
和它的怨种方法
size(),empty(),
erase(),clear(),
begin(),end(),back(),front()
pop_back(),push_back(),
insert(),swap(),resize()
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct review
{
    string title;
    int rating;
};
int main(void)
{
    bool _empty;
    int _front, _back;
    vector<int> ar_nums = {12, 23, 34}; //初始化vector容器
    vector<int> array(10);              //构建了一个包含十个int的容器
    vector<string> ar_string(3);
    vector<review> books(3);
    vector<review> oldtitle(books);
    vector<int>::iterator pi, pii; //构建了两个为vector的int类型规范声明的迭代器
    vector<string>::iterator pst;
    // cin>>ar_nums[0]>>ar_nums[1]>>ar_nums[2];
    cin >> ar_string[0] >> ar_string[1] >> ar_string[2];

    _front = ar_nums.front();
    //front()方法返回vector中的第一个元素
    _back = ar_nums.back();
    //back()方法返回vector中的最后一个元素
    ar_string.clear();
    //clear()方法清空vector，它通过vector调用
    _empty=ar_string.empty();
    //empty()方法返回vector是否为空，若为空则返回true，否则返回false
    for (int i = 0; i < 10; i++)
    {
        array[i] = i;
        ar_nums.push_back(i); 
        // push_back方法可以通过容器调用
        //作用是将元素i添加到vector(矢量)末尾，它将负责内存管理
        ar_string.push_back("hahah");
    }
    ar_nums.pop_back();
    // pop_back方法通过容器调用，作用是删除vector中最后一个元素
    //迭代器是一个广义指针，实际上，它可以是指针，也可是一个可对其执行类似指针的操作的对象
    for (pii = ar_nums.begin(); pii != ar_nums.end(); pii++)
    {
        //这里对它（迭代器）使用了指针的递增（++），和解除引用（*）
        cout << *pii << endl;
    }
    pi = ar_nums.end(); 
    // end方法返回一个表示超过容器尾的迭代器
    //这里的超过结尾的意思是指指向容器的最后一个元素的后面的那个元素
    pii = ar_nums.begin();      
    // begin方法返回一个指向容器中第一个元素的迭代器
    ar_nums.erase(pii + 3, pi); 
    // erase方法删除矢量中给定区间的元素，它接受两个迭代器参数，这些参数定义了要删除的区间
    //区间(pii+3,pi)包括pii+3，当不包括pi，左开右闭
    array.insert(array.begin(), ar_nums.begin(), ar_nums.end());
    // insert方法接受三个迭代器参数，第一个参数指定了新元素的插入位置，第二个和第三个迭代器参数定义了被插入区间（该区间往往是另一个容器对象的一部分）
    //也就是把一个容器的一部分插入到给定的一个容器的位置的后面
    int j = ar_nums.size(); 
    //但是虽然被插入的容器的元素增加了，但是插入的部分并不会减少
    // array.insert(array.begin(),ar_string.begin(),ar_string.end());
    //不能将不同数据类型的容器插入另一个容器当中
    cout << j << endl;
    for (pii = array.begin(); pii != array.end(); pii++)
    {
        cout << *pii << endl;
    }
    int nums = array.size();
    // size方法能够返回容器中元素数目
    cout << nums << endl;
    array.swap(ar_nums);
    //swap()方法接受一个容器，作用是交换这两个容器内的内容
    // array.swap(ar_string);
    //也不能交换两个数据类型不同的容器
    //当数据类型相同时，两个容器中元素数目可以不相同
    nums = array.size();
    // size方法能够返回容器中元素数目
    cout << nums << endl;
    array.resize(5);
    //resize()方法可以重新指定容器中有效的容器个数，当指定的比原来小时，只保留小的位数，当指定的比原来大时，补足那么多
    nums = array.size();
    cout << nums << endl;
    return 0;
}