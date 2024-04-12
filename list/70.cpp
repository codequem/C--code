#include <iostream>
#include <cstring>

using namespace std;
int main(void)
{
    int c, b;
    cin >> c >> b;
    int i, j, a[b];
    int result[b - c + 1];
    memset(result, 0, sizeof(result));
    for (i = 2; i < b; i++)
        a[i] = 1;
    for (i = 2; i < b; i++)
    {
        if (a[i])
        {
            for (j = i; j <= b / i; j++)
            {
                if (i * j >= c && i * j <= b)
                {
                    result[i * j - c] = max(result[i * j - c], i);
                    result[i * j - c] = max(result[i * j - c], j);
                }
                a[i * j] = 0;
            }
        }
    }
    for (i = 0; i <= b - c; i++)
    {
        if (i == b - c)
            cout << result[i] << endl;
        else
            cout << result[i] << ",";
    }
}