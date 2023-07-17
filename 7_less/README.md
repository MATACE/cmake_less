# Description
```
debug和release版本的编译
提供库的.cmake文件给find_package
```

# Build
```
mkdir build
cmake ..
cmake --build . -j 32
cmake --install .
# 指定安装路径
cmake --install . --prefix=安装路径
```

# debug
```
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . -j 32
```
# release
```
cd relaese
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . -j 32
```