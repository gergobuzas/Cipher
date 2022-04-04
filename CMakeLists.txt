cmake_minimum_required(VERSION 3.21)
project(Cipher)

set(CMAKE_CXX_STANDARD 11)

add_executable(Cipher main.cpp ciphers.cpp ciphers.h gtest_lite.h memtrace.cpp memtrace.h)
