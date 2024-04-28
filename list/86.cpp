#include <iostream>
#include <vector>

int maxCitizens(int n, int k, std::vector<std::vector<int>> &citizens)
{
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    // 初始化dp数组
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
        {
            dp[i][i + j] = citizens[i][j];
        }
    }

    int maxCitizenSum = 0;

    // 使用滑动窗口更新dp数组
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < k; ++j)
        {
            for (int l = i; l < n - 1 && l + j < n; ++l)
            {
                dp[i][l + j] = dp[i][l + j - 1] + citizens[l][j];
            }
        }
    }

    // 找到最大通行市民总数
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + k - 1; j < n; ++j)
        {
            maxCitizenSum = std::max(maxCitizenSum, dp[i][j]);
        }
    }

    return maxCitizenSum;
}

int main()
{
    int n, k;
    // std::cout << "Enter the number of intersections (n): ";
    std::cin >> n;
    // std::cout << "Enter the number of adjacent intersections to install device (k): ";
    std::cin >> k;

    std::vector<std::vector<int>> citizens(n, std::vector<int>(n, 0));
    // std::cout << "Enter the number of citizens passing through each intersection:" << std::endl;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            std::cin >> citizens[i][j];
        }
    }

    int maxCitizen = maxCitizens(n, k, citizens);
    // std::cout << "The maximum number of citizens that can receive propaganda is: " << maxCitizen << std::endl;
    std::cout << maxCitizen << std::endl;
    return 0;
}
