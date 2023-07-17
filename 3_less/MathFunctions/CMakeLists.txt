# TODO 14: Remove mysqrt.cxx from the list of sources

# TODO 1: 添加一个名为MathFunctions的库,其源代码为MathFunctions.cxx
# Hint: 您需要add_library命令
# 编译成静态文件
if(USE_MYMATH)
    add_library(MathFunc MathFunctions.cxx mysqrt.cxx)
    # 包含指定exe或library目标的头文件位置
    # CMAKE_CURRENT_SOURCE_DIR当前的CMakeLists的位置
    # INTERFACE 本目标不需要用,依赖这个目标的其他目标也需要用
    # PUBLIC    本目标需要用,依赖这个目标的其他目标也需要用
    # PRIVATE   本目标需要用,依赖这个目标的其他目标不需要用
    target_include_directories(MathFunc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
endif()
