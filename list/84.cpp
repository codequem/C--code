#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const string Name = "E22214111 程一帆";

typedef struct PCB
{
    string PID = "";       // 进程号
    double arrTime = 0;    // 到达时间
    double runTime = 0;    // 运行时间
    double startTime = -1; // 开始时间
    double finTime = 0;    // 完成时间
    double cycleTime = 0;  // 周转时间
    double wcTime = 0;     // 带权周转时间
    double already_runningTime = 0;
    char state = 'W'; // 作业状态，一开始默认就绪
    int priority = 255;
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

struct cmp3
{
    bool operator()(const PCB &P1, const PCB &P2)
    {
        if (P1.priority < P2.priority)
            return true;
        else if (P1.priority == P2.priority && P1.arrTime < P2.arrTime)
            return true;
        else
            return false;
    }
};

void FCFS(vector<PCB> &Process);
void SJF(vector<PCB> &Process);
void PSA(vector<PCB> &Process);
void RR(vector<PCB> &Process, int TimeSlice);
void print(vector<PCB> &Process);

int main(void)
{
    int num;
    PCB job;
    vector<PCB> Process;
    cout << Name << endl;
    cout << "请输入作业个数:";
    cin >> num;
    int TimeSlice = 0;
    int flag;
    cout << "您要使用哪种调度算法? 1:FCFS 2:SJF 3:PSA 4:RR ";
    cin >> flag;
    switch (flag)
    {
    case 1:
        cout << "请输入各作业的信息(格式：作业名 到达时间 服务时间)" << endl;
        for (int i = 0; i < num; i++)
        {
            cin >> job.PID >> job.arrTime >> job.runTime;
            Process.push_back(job);
        }
        FCFS(Process);
        break;
    case 2:
        cout << "请输入各作业的信息(格式：作业名 到达时间 服务时间)" << endl;
        for (int i = 0; i < num; i++)
        {
            cin >> job.PID >> job.arrTime >> job.runTime;
            Process.push_back(job);
        }
        SJF(Process);
    case 3:
        cout << "请输入各作业的信息(格式：作业名 到达时间 服务时间 优先级)" << endl;
        for (int i = 0; i < num; i++)
        {
            cin >> job.PID >> job.arrTime >> job.runTime >> job.priority;
            Process.push_back(job);
        }
        PSA(Process);
        break;
    case 4:
        cout << "请输入各作业的信息(格式：作业名 到达时间 服务时间)" << endl;
        for (int i = 0; i < num; i++)
        {
            cin >> job.PID >> job.arrTime >> job.runTime;
            Process.push_back(job);
        }
        cout << "请输入时间片的长度(以一为单位):" << endl;
        cin >> TimeSlice;
        RR(Process, TimeSlice);
        break;
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

void PSA(vector<PCB> &Process)
{
    vector<PCB> temp;
    int now = 0;
    do
    {
        int count = 0;
        sort(Process.begin(), Process.end(), cmp3());
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

void RR(vector<PCB> &Process, int TimeSlice)
{
    queue<PCB> Q;
    sort(Process.begin(), Process.end(), cmp1());
    for (auto it = Process.begin(); it != Process.end(); it++)
        Q.push(*it);
    int now = 0;
    int maxtime = 1000;
    Process.clear();
    while (!Q.empty() && now <= maxtime)
    {
        PCB ReadyProc = Q.front();
        if (ReadyProc.arrTime <= now)
        {
            ReadyProc.state = 'R';
            if (ReadyProc.startTime == -1)
                ReadyProc.startTime = now;
            if (ReadyProc.already_runningTime < ReadyProc.runTime)
            {
                now += min(TimeSlice, static_cast<int>(ReadyProc.runTime - ReadyProc.already_runningTime));
                ReadyProc.already_runningTime = min(ReadyProc.already_runningTime + TimeSlice, ReadyProc.runTime);
                ReadyProc.state = 'W';
            }
            if (ReadyProc.already_runningTime == ReadyProc.runTime)
            {
                ReadyProc.finTime = now;
                ReadyProc.cycleTime = ReadyProc.finTime - ReadyProc.arrTime;
                ReadyProc.wcTime = ReadyProc.cycleTime / ReadyProc.runTime;
                Process.push_back(ReadyProc);
                Q.pop();
                continue;
            }
        }
        Q.pop();
        Q.push(ReadyProc);
    }
}

void print(vector<PCB> &Process)
{
    int sum_runtime = 0;
    double sum_time = 0.00;
    double atime;  // 平均周转时间
    double awtime; // 平均带权周转时间
    printf("进程名  到达时间  运行时间  完成时间  周转时间  带权周转时间  优先级\n");
    // cout << "进程名 到达时间 运行时间 完成时间 周转时间 带权周转时间" << endl;
    for (auto it = Process.begin(); it != Process.end(); it++)
    {
        cout << (*it).PID;
        printf("       %.2f        %.2f       %.2f        %.2f        %.2f        %d\n", (*it).arrTime, (*it).runTime, (*it).finTime, (*it).cycleTime, (*it).wcTime, (*it).priority);
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