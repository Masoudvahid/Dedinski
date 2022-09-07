cmake_minimum_required(VERSION 3.21)
project(Dedinsky_summer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dedinsky_summer
        "Solution.cpp"
        "IO.cpp"
        "solver.cpp"
        "unit_test.cpp")
