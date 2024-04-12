#include <iostream>
#include <chrono>
#include <windows.h>
using namespace std;

class Timer
{
public:
    void startTimer()
    {
        start_time = std::chrono::steady_clock::now();
    }

    double stopTimer()
    {
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> time_taken = end_time - start_time;
        
        return time_taken.count();
    }

    void pauseTimer()
    {
        if (!paused)
        {
            pause_time = std::chrono::steady_clock::now();
            paused = true;
        }
    }

    void resumeTimer()
    {
        if (paused)
        {
            std::chrono::steady_clock::time_point resume_time = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed = resume_time - pause_time;
            start_time += std::chrono::duration_cast<std::chrono::steady_clock::duration>(elapsed);
            paused = false;
        }
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> start_time;
    std::chrono::time_point<std::chrono::steady_clock> pause_time;
    bool paused = false;
};