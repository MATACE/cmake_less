# TODO 1: 将CMake的最低版本设为 3.10
cmake_minimum_required(VERSION 3.10)

# TODO 2: 创建一个名为demo的项目
# project(Demo)
project(Demo VERSION 3.11)

message(STATUS "${PROJECT_VERSION_MAJOR}")
message(STATUS "${PROJECT_VERSION_MINOR}")

message(STATUS "Create Demo")
message(STATUS "${PROJECT_BINARY_DIR}")

# 设置字符串
set(DEBUG_NO "Debug Mode")

# TODO 7: 在上述项目命令中设置项目版本号为 1.0

# TODO 6: 设置变量CMAKE_CXX_STANDARD为11
#         变量CMAKE_CXX_STANDARD_REQUIRED为True
set(CMAKE_CXX_STANDARD 11)
# 标准不支持报错
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TODO 8: 使用configure_file命令配置并复制DemoConfig.h.in到
#         DemoConfig.h
configure_file(DemoConfig.h.in DemoConfig.h)

# TODO 3: 在项目中添加名为Demo的可执行文件
# Hint: 确保指定源文件为demo.cpp
# add_executable(demo 1.cpp 2.cpp demo.cpp)
add_executable(demo demo.cpp)

# TODO 9: 使用target_include_directories包含${PROJECT_BINARY_DIR}
# 被命名的 <target> 必须是由add_executable()或add_library()
# 命令创建的,并且不能是ALIAS target
# PRIVATE和PUBLIC项将填充<target>的INCLUDE_DIRECTORIES属性
# PUBLIC和INTERFACE项将填充<target>的INTERFACE_INCLUDE_DIRECTORIES属性
# target_include_directories(demo PUBLIC "${PROJECT_BINARY_DIR}" "第2个路径" "第三个路径")
target_include_directories(demo PUBLIC "${PROJECT_BINARY_DIR}" )
