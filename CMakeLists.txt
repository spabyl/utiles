#Minimum version of cmake
cmake_minimum_required(VERSION 3.28.0)
#project name my_app
project(app-core
    VERSION 1.0.0
    LANGUAGES C CXX
)
#copia los dll en el directorio del ejecutable al compilar
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
#el standar de c++ requerido
set(CMAKE_CXX_STANDARD 23)
#seleccionar el compilador
#set(CMAKE_CXX_COMPILER=clang++)
#cumplir el standar c++
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#extensiones c++
set(CMAKE_CXX_EXTENSIONS OFF)
#variable name of project
set(MY_EXECUTABLE_NAME app)
#add other subdirectories
add_subdirectory(app-core)
