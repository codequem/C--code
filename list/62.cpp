#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>

using namespace std;

int n, Num, MaxCnt;
int a[1000];

void read();
void write();
//将长度为n的一段数组分为中位数左边的部分、中位数、中位数右边的部分
void split(int a[], int n, int &l, int &r);
//求众数及其重数
void findMaxCnt(int &Num, int &MaxCnt, int a[], int n);

int main()
{
    read();
    sort(a, a + n);
    findMaxCnt(Num, MaxCnt, a, n);
    write();
    return 0;
}

void read()
{
    ifstream ifs;
    ifs.open("C:\\Users\\cyf\\Desktop\\in.txt", ios::in);
    ifs >> n;
    for (int i = 0; i < n; ++i)
        ifs >> a[i];
    ifs.close();
}

void write()
{
    ofstream ofs;
    ofs.open("C:\\Users\\cyf\\Desktop\\out.txt", ios::out);
    ofs << a[Num] << endl;
    ofs << MaxCnt << endl;
    ofs.close();
}

void split(int a[], int n, int &l, int &r)
{
    int mid = n >> 1;
    for (l = 0; l < n; ++l)
    {
        if (a[l] == a[mid])
        {
            //此时l为中位数第一次出现的位置
            break;
        }
    }
    for (r = l + 1; r < n; ++r)
    {
        if (a[r] != a[mid])
        {
            //此时r为中位数最后一次出现的下一个位置
            break;
        }
    }
}

void findMaxCnt(int &Num, int &MaxCnt, int a[], int n)
{
    int l, r;
    //将长度为n的一段数组分为中位数左边的部分、中位数、中位数右边的部分
    split(a, n, l, r);
    //此时的中位数
    int mid = n >> 1;
    //此时中位数的重数
    int cnt = r - l;
    //若该中位数的重数大于最大的重数，将该中位数更新为众数，该中位数的重数更新为最大重数
    if (cnt > MaxCnt)
    {
        MaxCnt = cnt;
        Num = mid;
    }
    //如果中位数左边的元素个数大于最大的重数，则继续递归
    if (l > MaxCnt)
        findMaxCnt(Num, MaxCnt, a, l);
    //如果中位数右边的元素个数大于最大的重数，则继续递归
    if (n - r > MaxCnt)
        findMaxCnt(Num, MaxCnt, a + r, n - r);
}
