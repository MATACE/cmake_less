# TODO 14: Remove mysqrt.cxx from the list of sources

# TODO 1: 添加一个名为MathFunctions的库,其源代码为MathFunctions.cxx
# Hint: 您需要add_library命令
# 编译成静态文件
if(USE_MYMATH)
    # 库的名字和.cmake的配置要匹配
    add_library(MathFunc MathFunctions.cxx mysqrt.cxx)
    # 包含指定exe或library目标的头文件位置
    # CMAKE_CURRENT_SOURCE_DIR当前的CMakeLists的位置
    # INTERFACE 本目标不需要用,依赖这个目标的其他目标也需要用
    # PUBLIC    本目标需要用,依赖这个目标的其他目标也需要用
    # PRIVATE   本目标需要用,依赖这个目标的其他目标不需要用
    # 不需要findpackage时
    # target_include_directories(MathFunc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    # 需要findpackage时,区别自己使用和别人使用的路径
    target_include_directories(MathFunc PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
    )
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
    # 安装库的静态库或者动态库到某个位置
    set(static_libs MathFunc)
    # 提供lib.cmake配置文件使用find_package
    install(TARGETS ${static_libs}
        EXPORT MathFunc
        DESTINATION "${CMAKE_SOURCE_DIR}/install/lib"
    )
    # 复制cmake文件到lib中
    install(EXPORT MathFunc
        FILE MathFunc.cmake
        DESTINATION "${CMAKE_SOURCE_DIR}/install/lib"
    )
    #安装库的头文件到某个位置
    set(incfiles
        "mysqrt.h"
        "MathFunctions.h")
    install(FILES ${incfiles} DESTINATION ${CMAKE_SOURCE_DIR}/install/inc)

    include(CMakePackageConfigHelpers)
    # 通过模板文件生成配置文件
    configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/MathFuncConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_SOURCE_DIR}/install/lib"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)
    # 生成版本
    write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/MathFuncVersion.cmake"
    VERSION "${Tutorial_VERSION_MAJOR}.${Tutorial_VERSION_MINOR}"
    COMPATIBILITY AnyNewerVersion
  )

    install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/MathFuncConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/MathFuncVersion.cmake
    DESTINATION "${CMAKE_SOURCE_DIR}/install/lib"
    )

endif()


# 给库构建一个.cmake配置文件,给别人用find_package进行使用
# target_include_directories时区别构建还是find_package
# install(TARGETS)时使用EXPORT导出为xxx.cmake
# install(EXPORT)时把xxx.cmake复制过去
# 在库下的CMakeLists.txt建立一个config.cmake.inf文件
