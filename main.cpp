#include <iostream>
#include "lib.h"

int main (int, char**)
{
    std::cout << "build " << lib::getVersion() << std::endl;
    std::cout << "Hello World!" << std::endl;
    return 0;
}
