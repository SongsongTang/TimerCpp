#pragma once

#include <iostream>
#include <chrono>

// Time the time during the block lifetime
class Timer
{
    private:
        const char* fFunctionName;
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        std::chrono::duration<float> duration;

    public:
        Timer(const char* functionName)
            : fFunctionName(functionName)
        {
            start = std::chrono::high_resolution_clock::now();
        }
        ~Timer()
        {
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;

            std::cout << fFunctionName
                      << " took "
                      << duration.count()
                      << "s \n";
        }
};
