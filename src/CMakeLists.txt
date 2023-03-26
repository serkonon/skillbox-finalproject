cmake_minimum_required(VERSION 3.24)

add_executable(${PROJECT_NAME} main.cpp
        ${PRJ_INCLUDE_DIR}/invertedindex.h invertedindex.cpp
        ${PRJ_INCLUDE_DIR}/converterjson.h converterjson.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PRJ_INCLUDE_DIR})