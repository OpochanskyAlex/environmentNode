cmake_minimum_required(VERSION 3.12)
project(testWithCmake)
set(CMAKE_CXX_STANDARD 11)

#include library pathes
include_directories (SimpleBufferDir PUBLIC "${PROJECT_SOURCE_DIR}/../../libs")
include_directories (GTestDir PUBLIC "${PROJECT_SOURCE_DIR}/gtest")

#add libraries's function implementation files
add_library(SimpleBufferLib EXCLUDE_FROM_ALL STATIC ../../libs/simple_buffer.c)
add_library(gtestLib EXCLUDE_FROM_ALL STATIC gtest/gtest-all.cc)

#add target with google tests
add_executable(testWithCmake
        gtest/gtest.h
        gtest/gtest-all.cc
        src/basic_check.cpp
        ${PROJECT_SOURCE_DIR}/../../libs/simple_buffer.h)
#add libraries to target
target_link_libraries(testWithCmake gtestLib)
target_link_libraries(testWithCmake SimpleBufferLib)

#add target with working program
add_executable(runmyapp src/main.cpp
        ${PROJECT_SOURCE_DIR}/../../libs/simple_buffer.h)
#add libraries to target
target_link_libraries (runmyapp SimpleBufferLib)

