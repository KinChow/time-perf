/*
 * @Author: Zhou Zijian 
 * @Date: 2023-02-23 22:57:37 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-04-04 13:39:26
 */

#ifndef TIME_PERF_H
#define TIME_PERF_H

#include <string>
#include <chrono>
#include <iostream>
#include "config.h"

#ifndef TIME_PERF_ON
#define TIME_PERF_ON 0
#endif

namespace Utils {
class TimePerf {
public:
    TimePerf(const char *name) : m_name(name), m_startTime(std::chrono::high_resolution_clock::now()) {}
    ~TimePerf()
    {
#if TIME_PERF_ON
        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> tm = endTime - m_startTime;
        std::cout << m_name << " cost : " << tm.count() << " ms" << std::endl;
#endif
    }

private:
    std::string m_name;
    std::chrono::high_resolution_clock::time_point m_startTime;
};
}  // namespace Utils

#ifndef TIMEPERF
#define TIMEPERF(x) Utils::TimePerf TIME_PERF_##x(#x);
#endif

#ifndef TIMEPERT_BEGIN
#define TIMEPERT_BEGIN(x) Utils::TimePerf *TIME_PERF_##x = new Utils::TimePerf(#x);
#endif

#ifndef TIMEPERT_END
#define TIMEPERT_END(x) delete TIME_PERF_##x;
#endif

#endif  // TIME_PERF_H
