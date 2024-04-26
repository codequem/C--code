#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string Name = "E22214111 程一帆";

typedef struct PCB
{
    string PID = "";      // 进程号
    double arrTime = 0;   // 到达时间
    double runTime = 0;   // 运行时间
    double startTime = 0; // 开始时间
    double finTime = 0;   // 完成时间
    double cycleTime = 0; // 周转时间
    double wcTime = 0;    // 带权周转时间
    char state = 'W';     // 作业状态，一开始默认就绪
    friend ostream &operator<<(ostream &out, PCB &P)
    {
        out << P.PID << ' ' << P.arrTime << ' ' << P.runTime << ' ' << P.startTime << ' ' << P.finTime << ' ' << P.cycleTime << ' ' << P.wcTime << ' ' << P.state << endl;
        return out;
    }
} PCB;

struct cmp1
{
    bool operator()(const PCB &P1, const PCB &P2)
    {
        return P1.arrTime <= P2.arrTime;
    }
};

struct cmp2
{
    bool operator()(const PCB &P1, const PCB &P2)
    {
        if (P1.runTime < P2.runTime)
            return true;
        else if (P1.runTime == P2.runTime && P1.arrTime < P2.arrTime)
            return true;
        else
            return false;
    }
};

void FCFS(vector<PCB> &Process);
void SJF(vector<PCB> &Process);
void print(vector<PCB> &Process);

int main(void)
{
    int num;
    PCB job;
    vector<PCB> Process;
    cout << Name << endl;
    cout << "请输入作业个数:";
    cin >> num;
    cout << "请输入各作业的信息(格式：作业名 到达时间 服务时间)" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> job.PID >> job.arrTime >> job.runTime;
        Process.push_back(job);
    }
    int flag;
    cout << "您要使用哪种调度算法? 1:FCFS 2:SJF";
    cin >> flag;
    switch (flag)
    {
    case 1:
        FCFS(Process);
        break;
    case 2:
        SJF(Process);
    default:
        break;
    }
    print(Process);
    return 0;
}

void FCFS(vector<PCB> &Process)
{
    int now = 0;
    sort(Process.begin(), Process.end(), cmp1());
    for (auto it = Process.begin(); it != Process.end(); it++)
    {
        if (now <= (*it).startTime)
            now = (*it).startTime;
        (*it).state = 'R';
        (*it).startTime = now;
        (*it).finTime = now + (*it).runTime;
        (*it).cycleTime = (*it).finTime - (*it).arrTime;
        (*it).wcTime = (*it).cycleTime / (*it).runTime;
        now = (*it).finTime;
        (*it).state = 'F';
    }
}

void SJF(vector<PCB> &Process)
{
    vector<PCB> temp;
    int now = 0;
    do
    {
        int count = 0;
        sort(Process.begin(), Process.end(), cmp2());
        auto it = Process.begin();
        while (now < (*it).arrTime)
        {
            if (it == Process.end())
                break;
            it++;
            count++;
        }
        if (it == Process.end())
            break;
        (*it).state = 'R';
        (*it).startTime = now;
        (*it).finTime = now + (*it).runTime;
        (*it).cycleTime = (*it).finTime - (*it).arrTime;
        (*it).wcTime = (*it).cycleTime / (*it).runTime;
        now = (*it).finTime;
        (*it).state = 'F';
        temp.push_back((*it));
        Process.erase(Process.begin() + count);
    } while (!Process.empty());
    for (auto it = temp.begin(); it != temp.end(); it++)
        Process.push_back(*it);
}

void print(vector<PCB> &Process)
{
    int sum_runtime = 0;
    double sum_time = 0.00;
    double atime;  // 平均周转时间
    double awtime; // 平均带权周转时间
    printf("进程名  到达时间 运行时间 完成时间 周转时间 带权周转时间\n");
    // cout << "进程名 到达时间 运行时间 完成时间 周转时间 带权周转时间" << endl;
    for (auto it = Process.begin(); it != Process.end(); it++)
    {
        cout << (*it).PID;
        printf("       %.2f        %.2f       %.2f        %.2f        %.2f\n", (*it).arrTime, (*it).runTime, (*it).finTime, (*it).cycleTime, (*it).wcTime);
        // cout<<(*it)<<endl;
        sum_runtime += (*it).cycleTime;
        sum_time += (*it).wcTime;
    }
    atime = sum_runtime * 1.0 / Process.size();
    awtime = sum_time * 1.000 / Process.size();
    printf("平均周转时间:%.2f \n", atime);
    printf("平均带权周转时间:%.3f \n", awtime);
    printf("\n");
}