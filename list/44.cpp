
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(0, 9);
 
    std::vector<int> v1(10), v2(10);
    std::generate(v1.begin(), v1.end(), std::bind(dis, std::ref(mt)));
    std::generate(v2.begin(), v2.end(), std::bind(dis, std::ref(mt)));
	std::vector<int> dst;
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(),std::back_inserter(dst));
    for(auto b=dst.begin();b!=dst.end();b++)
    cout<<*b;
    int x;
    cin>>x;
}