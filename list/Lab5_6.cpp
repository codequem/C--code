#include <iostream>
#include <string>
#include "stdlib.h"
#define maxsize 1000 // 定义最大数组域
using namespace std;

const string name = "E22214111 程一帆";

// 先来先服务调度算法
void FIFO(int array[], int m)
{
    int sum = 0, j, i, now;
    float avg;
    cout << "\n 请输入当前的磁道号： ";
    cin >> now;
    cout << "\n FIFO 调度结果: " << now << " ";
    for (i = 0; i < m; i++)
        cout << array[i] << " ";
    sum = abs(now - array[0]);
    for (j = 1; j < m; j++)
        sum += abs(array[j] - array[j - 1]); // 累计总的移动距离
    avg = (float)sum / m;                    // 计算平均寻道长度
    cout << "\n 移动的总道数： " << sum << endl;
    cout << " 平均寻道长度： " << avg << endl;
}
// 最短寻道时间优先调度算法
void SSTF(int array[], int m)
{
    int temp;
    int k = 1;
    int now, l, r;
    int i, j, sum = 0;
    float avg;
    for (i = 0; i < m; i++)
    {
        for (j = i + 1; j < m; j++) // 对磁道号进行从小到大排列
        {
            if (array[i] > array[j]) // 两磁道号之间比较
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (i = 0; i < m; i++) // 输出排序后的磁道号数组
        cout << array[i] << " ";
    cout << "\n 请输入当前的磁道号： ";
    cin >> now;
    cout << "\n SSTF 调度结果: ";
    if (array[m - 1] <= now) // 判断整个数组里的数是否都小于当前磁道号
    {
        for (i = m - 1; i >= 0; i--) // 将数组磁道号从大到小输出
            cout << array[i] << " ";
        sum = now - array[0]; // 计算移动距离
    }
    else if (array[0] >= now) // 判断整个数组里的数是否都大于当前磁道号
    {
        for (i = 0; i < m; i++) // 将磁道号从小到大输出
            cout << array[i] << " ";
        sum = array[m - 1] - now; // 计算移动距离
    }
    else
    {
        while (array[k] < now) // 逐一比较以确定 K 值
        {
            k++;
        }
        l = k - 1;
        r = k;
        // 确定当前磁道在已排的序列中的位置
        while ((l >= 0) && (r < m))
        {
            if ((now - array[l]) <= (array[r] - now)) // 判断最短距离
            {
                cout << array[l] << " ";
                sum += now - array[l]; // 计算移动距离
                now = array[l];
                l = l - 1;
            }
            else
            {
                cout << array[r] << " ";
                sum += array[r] - now; // 计算移动距离
                now = array[r];
                r = r + 1;
            }
        }
        if (l == -1)
        {
            for (j = r; j < m; j++)
            {
                cout << array[j] << " ";
            }
            sum += array[m - 1] - array[0]; // 计算移动距离
        }
        else
        {
            for (j = l; j >= 0; j--)
            {
                cout << array[j] << " ";
            }
            sum += array[m - 1] - array[0]; // 计算移动距离
        }
    }
    avg = (float)sum / m;
    cout << "\n 移动的总道数： " << sum << endl;
    cout << " 平均寻道长度： " << avg << endl;
}
/// 扫描算法
void SCAN(int array[], int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++) // 对磁道号进行从小到大排列
        {
            if (array[i] > array[j]) // 两磁道号之间比较
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << array[i] << " ";
    }
    int now;
    cout << "\n 请输入当前的磁道号： ";
    cin >> now;
    cout << "\n SCAN 调度结果：";
    int pos;
    for (int i = 0; i < m; i++)
    {
        if (array[i] >= now)
        {
            pos = i;
            sum += abs(array[i] - now);
            break;
        }
    }
    for (int i = pos; i < m; i++)
    {
        if (i != pos)
            sum += abs(array[i] - array[i - 1]);
        cout << array[i] << " ";
    }
    if (pos >= 1)
        sum += abs(array[m - 1] - array[pos - 1]);
    for (int i = pos - 1; i >= 0; i--)
    {
        if (i)
            sum += abs(array[i] - array[i - 1]);
        cout << array[i] << " ";
    }
    cout << "\n 移动的总道数： " << sum << endl;
    cout << " 平均寻道长度： " << 1.0 * sum / m << endl;
}
/// 循环扫描算法
void CSCAN(int array[], int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++) // 对磁道号进行从小到大排列
        {
            if (array[i] > array[j]) // 两磁道号之间比较
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << array[i] << " ";
    }
    int now;
    cout << "\n 请输入当前的磁道号： ";
    cin >> now;
    cout << "\n C-SCAN 调度结果：";
    int pos;
    for (int i = 0; i < m; i++)
    {
        if (array[i] >= now)
        {
            pos = i;
            sum += abs(array[i] - now);
            break;
        }
    }
    for (int i = pos; i < m; i++)
    {
        if (i != pos)
            sum += abs(array[i] - array[i - 1]);
        cout << array[i] << " ";
    }
    if (pos >= 1)
        sum += abs(array[m - 1] - array[0]);
    for (int i = 0; i < pos; i++)
    {
        if (i)
            sum += abs(array[i] - array[i - 1]);
        cout << array[i] << " ";
    }
    cout << "\n 移动的总道数： " << sum << endl;
    cout << " 平均寻道长度： " << 1.0 * sum / m << endl;
}
// 操作界面
int main()
{
    cout << name << endl;

    int c;
    int count;
    // int m=0;
    int cidao[maxsize]; // 定义磁道号数组
    int i = 0;
    int b;
    cout << "\n --------------------------------------------------\n";
    cout << " 磁盘调度算法模拟";
    cout << "\n --------------------------------------------------\n";
    cout << "请先输入磁道数量： \n";
    cin >> b;
    printf("请先输入磁道序列： \n");
    for (i = 0; i < b; i++)
    {
        cin >> cidao[i];
    }
    printf("\n 磁道读取结果： \n");
    for (i = 0; i < b; i++)
    {
        cout << cidao[i] << " "; // 输出读取的磁道的磁道号
    }
    count = b;
    cout << endl;
    while (1)
    {
        cout << "\n 算法选择： \n";
        cout << " 1、先进先出算法（ FIFO） \n";
        cout << " 2、最短服务时间优先算法（ SSTF） \n";
        cout << " 3、扫描算法（ SCAN） \n";
        cout << " 4、循环扫描算法（ C-SCAN） \n";
        cout << " 5. 退出\n";
        cout << "\n";
        cout << "请选择： ";
        cin >> c;
        if (c > 5)
            break;
        switch (c)
        {
        case 1:
            FIFO(cidao, count); // FIFO algorithm
            cout << "\n";
            break;
        case 2:
            SSTF(cidao, count); // SSTF algorithm
            cout << "\n";
            break;
        case 3:
            SCAN(cidao, count); // SCAN algorithm
            cout << "\n";
            break;
        case 4:
            CSCAN(cidao, count); // C-SCAN algorithm
            cout << "\n";
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
