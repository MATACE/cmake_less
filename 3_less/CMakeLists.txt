cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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

message(STATUS ${USE_MYMATH})

# add the executable
add_executable(Tutorial tutorial.cxx)

# TODO 3: 使用target_link_libraries将库链接到我们的可执行文件中
# 后面跟库的名字
# 相当于 -lMathFunc
# 链接静态文件
# target_link_libraries(Tutorial PUBLIC MathFunc)
# 有list变量后
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

