cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

option(BUILD_SHARED_LIBS "Build the project shared library" OFF)
# .a .lib静态库位置
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/install")
# .dll exe 可执行文件位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/install")
# .so 库位置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/install")

message(STATUS "$ENV{PATH}")

# set 分类型保存
set(OOP OFF CACHE BOOL "set xxx" FORCE)
set(TEST_VAL "" CACHE STRING "more this" FORCE)
set_property(CACHE TEST_VAL PROPERTY STRINGS one two thrid)

# specify the C++ standard
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)
# 使用虚拟库设置C++ standard编译选项
# 添加C++11编译特性到虚拟库
# 创建虚拟库
add_library(cxx_flags INTERFACE)
# 设置虚拟库的特性
target_compile_features(cxx_flags INTERFACE cxx_std_11)

# TODO 7: 使用option创建变量USE_MYMATH，并设置默认值为 ON/OFF
option(USE_MYMATH "checkout " ON)
option(USE_MYSQRT "checkout " ON)
# 当USE_MYMATH为ON时才编译库
if(USE_MYMATH)
    # TODO 2: 使用add_subdirectory()将MathFunctions文件夹添加到该项目中
    add_subdirectory(MathFunctions)
    # List APPEND(追加) 列表名 追加到库的内容
    # 追加库
    list(APPEND THIRD_LIBS MathFunc)
    # 追加库的头文件,让库自己做
    # list(APPEND THIRD_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# configure a header file to pass some of the CMake settings
# to the source code
# 头文件要在配置之后生成
configure_file(TutorialConfig.h.in TutorialConfig.h)
# 安装TutorialConfig.h文件
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION ${PROJECT_SOURCE_DIR}/install/inc)

message(STATUS ${USE_MYMATH})

# 生成器控制编译器
# 在make阶段根据变量不同的值来区别编译器
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# 向虚拟的变量设置编译选项
# 创建虚拟库
add_library(cc_flags INTERFACE)
# 设置虚拟库的特性
target_compile_features(cc_flags INTERFACE cxx_std_11)
# 设置虚拟库的编译参数
target_compile_options(cc_flags INTERFACE
    "$<${gcc_like_cxx}:-Wall; -g>"
    "$<${msvc_cxx}:-W3>"
)

# Debug打包的名字
set(CMAKE_DEBUG_POSTFIX d)

# 目标必须在前面,后面才能设置目标
# add the executable
add_executable(Tutorial tutorial.cxx)

# 添加Debug属性
set_target_properties(Tutorial PROPERTIES CMAKE_DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

target_compile_definitions(Tutorial PUBLIC "AUTO_MAROS")

# 之间通过参数设置C++11标准
set_property(TARGET Tutorial PROPERTY CXX_STANDARD 11)
set_property(TARGET Tutorial PROPERTY CXX_STAND)

# TODO 3: 使用target_link_libraries将库链接到我们的可执行文件中
# 后面跟库的名字
# 相当于 -lMathFunc
# 链接静态文件
# target_link_libraries(Tutorial PUBLIC MathFunc)
# 有list变量后
# 链接设置后的虚拟库设置C++11标准
# target_link_libraries(Tutorial PUBLIC ${THIRD_LIBS} cxx_flags)
target_link_libraries(Tutorial PUBLIC ${THIRD_LIBS})

# TODO 4: Add MathFunctions to Tutorial's target_include_directories()
# Hint: ${PROJECT_SOURCE_DIR} is a path to the project source. AKA This folder!

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# 添加库文件的目录路径
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                        #  无list变量
                        #    "${PROJECT_SOURCE_DIR}/MathFunctions"
                        # 有list变量后,让库自己做
                            # "${THIRD_INCLUDES}"
                           )
# 引用第三方库的位置,第三方库包含在自己的CmakeList.txt工程中
# 指定位置
# set(opencv_dir "${PROJECT_SOURCE_DIR}/lib/opencv")
# 添加到Tutorial目标中
# target_include_directories(Tutorial PRIVATE "${opencv_dir}"/include)
# target_link_directories(Tutorial PRIVATE "${opencv_dir}"/lib)
# target_link_libraries(Tutorial PRIVATE OpenCV)

# 引用第三方库的位置,第三方库不包含在自己的CmakeList.txt工程中
# 设置第三方库库位置(可省略)
# set(OpenCV_DIR "xxxxx")
# find_package(OpenCV REQUIRED)
# target_link_libraries(Tutorial PRIVATE OpenCV)

# 添加自定义命令
# make uninstall
add_custom_target("uninstall" COMMENT "Uninstall installed files")
add_custom_command(
    TARGET "uninstall"
    POST_BUILD
    COMMENT "Uninstall files with install_manifest.txt"
    COMMAND xargs rm -vf < install_manifest.txt || echo Nothing in
            install_manifest.txt to be uninstalled!
)

# 安装install到指定的目录
# install(TARGETS targets... [DESTINATION <dir>])
# 默认指定的安装路径
# 测试路径
# message(STATUS ${CMAKE_INSTALL_PREFIX})
# message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
# message(STATUS ${CMAKE_CURRENT_LIST_DIR})
# message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})

#安装可执行文件到某位置
install(TARGETS Tutorial DESTINATION ${CMAKE_CURRENT_LIST_DIR}/install/bin)
#在库的CMakeLists.txt中写

# 测试程序是否正常
enable_testing()

# 添加测试
# 名字 命令 参数
add_test(NAME Run COMMAND Tutorial 10)

# 测试用列
add_test(NAME Test1 COMMAND Tutorial 4)
# 正则匹配结果
set_tests_properties(Test1 PROPERTIES PASS_REGULAR_EXPRESSION "4 is 2")

# 打包成二进制文件
include(InstallRequiredSystemLibraries)
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)
