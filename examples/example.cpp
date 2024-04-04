/*
 * @Author: Zhou Zijian 
 * @Date: 2023-02-23 23:46:36 
 * @Last Modified by: Zhou Zijian
 * @Last Modified time: 2024-04-04 12:15:19
 */

#include <iostream>
#include "TimePerf.h"

void Fun()
{
    int j = 0;
    for (size_t i = 0; i < 2000000; i++) {
        j += i;
    }
}

void Usage1()
{
    Utils::TimePerf Test(__FUNCTION__);
    Fun();
}

void Usage2()
{
    TIMEPERF(Usage2);
    Fun();
}

void Usage3()
{
    TIMEPERT_BEGIN(Usage3);
    Fun();
    TIMEPERT_END(Usage3);
}

int main()
{
    Usage1();
    Usage2();
    Usage3();
}
