# Description
```
mkdir build
cmake ..
cmake --build .
cmake --install .
# 指定安装路径
cmake --install . --prefix=安装路径
```

# debug
```
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
```
# release
```
cd relaese
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```