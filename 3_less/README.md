# Descption
```
CMakeLists中如何生成一个库,让库自己包含自己的头文件,并被定成的CMakeLists.txt引用
```

# Build
```bash
mkdir build
cmake ..
make -j4
# Other
mkdir build
cmake ..
cmake --build . -j4
```