#include <iostream>
#include <chrono>
#include <random>
#define Maxn 12
int arr[Maxn];
using namespace std;

int main(void)
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int num = 0;
    int x = 0;
    while (cin >> x)
    {
        arr[num++] = x;
    }
    cout << "Result:";
    for (int j = 1; j < num; j++)
        cout << arr[j] << ' ';
    cout << arr[0];
    if (rng() & 1)
        cout << ' ';
    return 0;
}