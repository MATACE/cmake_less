#include <iostream>

// TODO 11: Include DemoConfig.h
#include "DemoConfig.h"

int main(int argc, char* argv[])
{
    std::cout << "hello world" << std::endl;
    std::cout << PROJECT_VERSION_MAJOR << " " << PROJECT_VERSION_MINOR << std::endl;
    std::cout << DEBUG_NO  << std::endl;

    return 0;
}
