// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>


// 包含库的头文件
#include "MathFunctions.h"


int main(int argc, char* argv[])
{

  // convert input to double
  const double inputValue = std::stod(argv[1]);

#ifdef AUTO_MAROS
// 为目标添加编译定义,相当于自动存在#define AUTO_MAROS
    std::cout << "AUTO MAROS" << std::endl;
#endif

  // calculate square root
  // 使用mysqrt
  const double outputValue = mathfunctions::sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
