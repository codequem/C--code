#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>

using namespace std;

int Distance = 0;
string A, B;

int editDistance(const char *str1, const char *str2);

void read()
{
    ifstream ifs;
    ifs.open("C:\\Users\\cyf\\Desktop\\in.txt", ios::in);
    ifs >> A;
    ifs >> B;
    ifs.close();
}

void write()
{
    ofstream ofs;
    ofs.open("C:\\Users\\cyf\\Desktop\\out.txt", ios::out);
    ofs << Distance << endl;
    ofs.close();
}

int main()
{
    read();
    Distance = editDistance(A.c_str(), B.c_str());
    write();
    return 0;
}

int editDistance(const char *str1, const char *str2)
{
    int i, j;
    int dp[strlen(str1) + 1][strlen(str2) + 1];

    for (i = 0; i <= strlen(str1); i++)
    {
        for (j = 0; j <= strlen(str2); j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else

                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
        }
    }
    return dp[strlen(str1)][strlen(str2)];
}