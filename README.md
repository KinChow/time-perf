# TimePerf

#### 介绍
函数耗时统计




#### 安装教程

```shell
cmake -B build -DENABLE_EXAMPLE=ON -DENABLE_TIME_PERF=ON
# 如果需要构建例子-DENABLE_EXAMPLE=ON，否则-DENABLE_EXAMPLE=OFF
# 如果需要使能耗时统计-DENABLE_TIME_PERF=ON，否则-DENABLE_TIME_PERF=OFF
cmake --build build
```



#### 使用说明

参考`examples`目录下的example.cpp。
