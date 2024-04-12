//在unordered_map 的value中尝试装一个vector
//再实验一下unordered_map里面给的哈希函数
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>

std::ostream& operator<<
(std::ostream &os,std::unordered_map<std::string,std::vector<int>>::iterator mymap){
    os<<mymap->first<<std::endl;
    for(auto i=mymap->second.begin();i!=mymap->second.end();i++)
            os<<*i<<' ';
    os<<std::endl;
    return os;
}

int main (void)
{
    std::unordered_map<std::string,std::vector<int>> mymap;
    std::vector<int> v{1,2,3};
    mymap.emplace("wuhu",v);
    v.emplace_back(4);
    mymap.emplace("aha",v);
    v.emplace_back(5);
    mymap.emplace("ah",v);
    v.emplace_back(6);
    mymap.emplace("a",v);
    for(auto i=mymap.begin();i!=mymap.end();i++)
        std::cout<<i<<std::endl;
    std::unordered_map<std::string,std::vector<int>>::hasher ha=mymap.hash_function();//现在这个ha就是一个函数
    for(auto i=mymap.begin();i!=mymap.end();i++)
    std::cout<<ha(i->first)<<std::endl;
    system("pause");
    return 0;
}