#include <bits/stdc++.h>

using namespace std;
struct Compare
{
    bool operator()(string &a, string &b)
    {
        return a.length() >= b.length();
    }
};

int main(void)
{
    string strs[5] = {"1", "12", "123", "1234", "12345"};
    sort(strs, strs + 5, Compare());
    for (int i = 0; i < 5; i++)
        cout << strs[i] << endl;
    return 0;
}