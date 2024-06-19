#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <string>

using namespace std;

const string name = "E22214111 程一帆";

int findOptimal(int pages[], int n, int index, int frame[], int f)
{
    int res = -1;
    int farthest = index;
    for (int i = 0; i < f; i++)
    {
        int j;
        for (j = index; j < n; j++)
        {
            if (frame[i] == pages[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return (res == -1) ? 0 : res;
}

void optimalPage(int pages[], int n, int f)
{
    int frame[f];
    for (int i = 0; i < f; i++)
        frame[i] = -1;

    int hit = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < f; j++)
            if (frame[j] == pages[i])
            {
                hit++;
                break;
            }

        if (j == f)
        {
            int l = findOptimal(pages, n, i + 1, frame, f);
            frame[l] = pages[i];
        }

        cout << endl;
        for (int k = 0; k < f; k++)
            cout << frame[k] << ' ';
    }
    cout << "\n\n缺页次数 : " << n - hit;
    cout << "\n缺页率:" << (n - hit) / static_cast<double>(n) << endl;
}

void fifoPage(int pages[], int n, int f)
{
    int frame[f];
    for (int i = 0; i < f; i++)
        frame[i] = -1;

    int hit = 0;
    int pointer = 0;
    for (int i = 0; i < n; i++)
    {
        bool allocated = false;
        for (int j = 0; j < f; j++)
            if (frame[j] == pages[i])
            {
                hit++;
                allocated = true;
                break;
            }

        if (!allocated)
        {
            frame[pointer] = pages[i];
            pointer = (pointer + 1) % f;
        }

        cout << endl;
        for (int k = 0; k < f; k++)
            cout << frame[k] << ' ';
    }
    cout << "\n\n缺页次数 : " << n - hit;
    cout << "\n缺页率:" << (n - hit) / static_cast<double>(n) << endl;
}

int findLRU(int time[], int f)
{
    int min = time[0];
    int res = 0;
    for (int i = 1; i < f; i++)
    {
        if (time[i] < min)
        {
            min = time[i];
            res = i;
        }
    }
    return res;
}

void lruPage(int pages[], int n, int f)
{
    int frame[f];
    for (int i = 0; i < f; i++)
        frame[i] = -1;

    int time[f];
    for (int i = 0; i < f; i++)
        time[i] = 0;

    int hit = 0;
    for (int i = 0; i < n; i++)
    {
        bool allocated = false;
        for (int j = 0; j < f; j++)
            if (frame[j] == pages[i])
            {
                hit++;
                time[j] = i + 1;
                allocated = true;
                break;
            }

        if (!allocated)
        {
            int lru = findLRU(time, f);
            frame[lru] = pages[i];
            time[lru] = i + 1;
        }

        cout << endl;
        for (int k = 0; k < f; k++)
            cout << frame[k] <<' ';
    }
    cout << "\n\n缺页次数 : " << n - hit;
    cout << "\n缺页率:" << (n - hit) / static_cast<double>(n) << endl;
}

int main()
{
    cout<<name<<endl;

    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int f = 3;

    int c = 0;
    cout << "请选择你要使用的缺页调度算法:1:最佳置换算法,2:先进先出算法,3:LRU算法  ";
    cin >> c;
    switch (c)
    {
    case 1:
        optimalPage(pages, n, f);
        break;
    case 2:
        fifoPage(pages, n, f);
        break;
    case 3:
        lruPage(pages, n, f);
        break;
    default:
        cout << "您没有选择任何缺页调度算法，程序结束";
        break;
    }

    return 0;
}
