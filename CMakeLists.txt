cmake_minimum_required(VERSION 3.8)
project(exercise_code_clion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp include/Exercise_13.39.h src/Exercise_13.39.cpp app/Exercise_13.39/test.cpp)
add_executable(exercise_code_clion ${SOURCE_FILES})