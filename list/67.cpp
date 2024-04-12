#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int filenum = 0;
vector<int> oddlist;

double result = 0;

double solve(int, vector<int> &);

void read()
{
    ifstream ifs;
    ifs.open("C:\\Users\\cyf\\Desktop\\in.txt", ios::in);
    ifs >> filenum;
    for (int i = 0; i < filenum; i++)
    {
        int temp;
        ifs >> temp;
        oddlist.push_back(temp);
    }
    ifs.close();
}

void write()
{
    ofstream ofs;
    ofs.open("C:\\Users\\cyf\\Desktop\\out.txt", ios::out);
    ofs << result << endl;
    ofs.close();
}

int main()
{
    read();
    result = solve(filenum, oddlist);
    write();
    return 0;
}

//使用贪心算法，将vec中的值排序使其元素大小的分布从中间往两边递减
double solve(int n, vector<int> &oddlist)
{
    sort(oddlist.begin(), oddlist.end(), greater<int>());
    int mid = n / 2;
    int temp[n + 1];
    int sum = 0;
    temp[mid] = oddlist[0];
    sum += temp[mid];
    for (int i = 1, k = 1; i < n; i++, k++)
    {
        temp[mid - k] = oddlist[i];
        sum += temp[mid - k];
        i++;
        if (i != n)
        {
            temp[mid + k] = oddlist[i];
            sum += temp[mid + k];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            result += (temp[i] * 1.0 / sum) * (temp[j] * 1.0 / sum) * (j - i);
    }
    return result;
}