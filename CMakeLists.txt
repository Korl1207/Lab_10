cmake_minimum_required(VERSION 3.10)
project(Lab_10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(prog
  src/main.cpp
  src/MyPipeLine.hpp
)

include_directories(src)