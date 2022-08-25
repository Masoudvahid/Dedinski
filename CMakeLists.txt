cmake_minimum_required(VERSION 3.21)
project(Dedinsky_summer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dedinsky_summer
        "summer_2022/task_1_quadratic_equation/Solution.cpp"
        "summer_2022/task_1_quadratic_equation/IO.cpp"
        "summer_2022/task_1_quadratic_equation/solver.cpp"
        "summer_2022/task_1_quadratic_equation/unit_test.cpp")
