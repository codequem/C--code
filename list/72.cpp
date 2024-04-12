#include <iostream>
using namespace std;

int calculateInsects(int months, int x, int y)
{
    int adults = 1; // 初始成虫对数为1对
    int eggs = 0;   // 初始卵对数为0对

    for (int i = 1; i <= months; ++i)
    {
        if (i % x == 0)
        {                       // 每隔x个月产卵
            eggs += adults * y; // 每对成虫产生y对卵
        }
        if (i % 2 == 0)
        { // 每隔两个月卵孵化成成虫
            adults += eggs;
            eggs = 0; // 成虫长成后，卵数量清零
        }
    }
    return adults;
}

int main()
{
    int Z, X, Y;
    //cout << "请输入过去的月数Z，每对成虫过x个月产y对卵的x和y：" << endl;
    cin >> Z >> X >> Y;

    int totalInsects = calculateInsects(Z, X, Y);
    cout << totalInsects << endl;

    return 0;
}
