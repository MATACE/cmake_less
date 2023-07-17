cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial)

set(MathFunc_DIR "/home/mat/workspace/cmake/cmake_new_less/7_less/install/lib")
find_package(MathFunc REQUIRED)

add_executable(Tutorial tutorial.cxx)
target_link_libraries(Tutorial PUBLIC MathFunc)
