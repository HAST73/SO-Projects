cmake_minimum_required(VERSION 3.23)
project(SO_Projects)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(SO_Projects
        Sources/RunFile.cpp Sources/Philosopher.cpp Sources/Waiter.cpp Headers/Philosopher.h Headers/Waiter.h)
