cmake_minimum_required(VERSION 3.8)
project(exercise_code_clion)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_compile_options(
        -std=c++11
        -O3
        -lstdc++
)

add_subdirectory(app)

