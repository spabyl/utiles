module;

#include <string>

export module utiles;

import <iostream>;

export void hola()
{
    std::cout << "hola" << std::endl;
}

namespace okis
{
    export void it_ok() {}
}
