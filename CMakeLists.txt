cmake_minimum_required(VERSION 3.20)

set(DEBUG_VERSION "DebugMode")
set(RELEASE_VERSION "ReleaseMode")
set(COMPILE_MODE ${DEBUG_VERSION})
set(PROJECT_NAME "TimePerf")

if (NOT DEFINED MASTER_PROJECT)
    set(MASTER_PROJECT OFF)
    if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
        set(MASTER_PROJECT ON)
    endif()
    message(STATUS "${PROJECT_NAME}: MASTER_PROJECT: ${MASTER_PROJECT}")
endif()

# debug mode (project name + compile time)
if(${COMPILE_MODE} MATCHES ${DEBUG_VERSION})
    set(USE_RELEASE_MODE 0)
    set(CMAKE_BUILD_TYPE "Debug")
# release mode (project name + version)
else()
    set(USE_RELEASE_MODE 1)
    set(CMAKE_BUILD_TYPE "Release")
endif()

string(TIMESTAMP COMPILE_TIME %y%m%d_%H%M%S)
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)
set(VERSION_TWEAK 2)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

option(ENABLE_TIME_PERF "Enable TimePerf" OFF)

option(ENABLE_EXAMPLE "Enable examples of TimePerf." OFF)

if (ENABLE_TIME_PERF)
add_definitions(-DTIME_PERF_ON=1)
endif()

configure_file(
    "${PROJECT_SOURCE_DIR}/include/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}
)

if (ENABLE_EXAMPLE)
add_subdirectory(examples)
endif()