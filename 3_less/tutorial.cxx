// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>

// TODO 5: Include MathFunctions.h
#include "TutorialConfig.h"

// 包含库的头文件
#ifdef USE_MYSQRT
#include "mysqrt.h"
#else
#include "MathFunctions.h"
#endif

#include "TutorialConfig.h"

int main(int argc, char* argv[])
{
  if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]);

  // calculate square root
  // 使用mysqrt
#ifdef USE_MYSQRT
  const double outputValue = mathfunctions::detail::mysqrt(inputValue);
#else
  const double outputValue = mathfunctions::sqrt(inputValue);
#endif
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
