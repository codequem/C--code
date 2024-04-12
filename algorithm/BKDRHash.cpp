/*2022年12月29日12:24:33
BKDRHash函数的实现*/
//也就是单哈希
#include <iostream>
#include <string>

using namespace std;
unsigned int BKDRHash(const char *str);

unsigned int BKDRHash(const char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str){
        hash = hash * seed + (*str++);//这里是自然取模，mod2^64-1，也就是让他自然溢出后自然相当于取模了
    }

    return (hash & 0x7FFFFFFF);
}