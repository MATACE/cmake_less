# TODO 14: Remove mysqrt.cxx from the list of sources

# TODO 1: 添加一个名为MathFunctions的库，其源代码为 MathFunctions.cxx
# and mysqrt.cxx
# Hint: 您需要add_library命令
# 编译成静态文件
if(USE_MYMATH)
    add_library(MathFunc MathFunctions.cxx mysqrt.cxx)
endif()

# TODO 8: 如果 USE_MYMATH开，则使用target_compile_definitions传递
# USE_MYMATH作为一个预编译定义到我们的源文件中

# TODO 12: 当USE_MYMATH为ON时，为SqrtLibrary添加一个库，库名为
# source mysqrt.cxx

# TODO 13: 当USE_MYMATH为ON时，将SqrtLibrary链接到MathFunctions库
