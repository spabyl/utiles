module;

#include <string>

export module utiles;

import <iostream>;

export void hola()
{
    std::cout << "hola desde el módulo .." << std::endl;
}
export void hello()
{
    std::cout << "hello from module .." << std::endl;
}
namespace okis
{
    export void it_ok() {}
}
