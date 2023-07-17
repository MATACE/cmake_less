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
    # 之间通过参数设置C++11标准
    set_property(TARGET MathFunc PROPERTY CXX_STANDARD 11)
    set_property(TARGET MathFunc PROPERTY CXX_STANDARD_REQUIRED ON)
    # 通过虚拟库设置C++标准
    # target_link_libraries(MathFunc PUBLIC cxx_flags)
    # message(STATUS ${CMAKE_INSTALL_PREFIX})
    message(STATUS ${CMAKE_SOURCE_DIR})
    # message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
    # message(STATUS ${CMAKE_CURRENT_LIST_DIR})
    # message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
    # message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
    # 每个cmake build都有自己的文件夹
    #安装库的静态库或者动态库到某个位置
    set(static_libs MathFunc)
    install(TARGETS ${static_libs} DESTINATION ${CMAKE_SOURCE_DIR}/install/lib)
    #安装库的头文件到某个位置
    set(incfiles
        "mysqrt.h"
        "MathFunctions.h")
    install(FILES ${incfiles} DESTINATION ${CMAKE_SOURCE_DIR}/install/inc)
endif()
