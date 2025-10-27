#create a ejecutable name with sources
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, e.g. Debug, Release, RelWithDebInfo, MinSizeRel." FORCE)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(MY_DEBUG_MACRO)
    add_compile_definitions("$<$<CONFIG:Debug>:MY_DEBUG_MACRO>")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DMY_DEBUG_MACRO")
endif()


if(WIN32)
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        set(WIN_ICO ${CMAKE_SOURCE_DIR}/res/res.o)
    elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(MY_EXECUTABLE_NAME app_d)
    endif()
else()
    set(WIN_ICO)
endif(WIN32)

add_executable(
    ${MY_EXECUTABLE_NAME} ${WIN_ICO}
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/main_test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utiles.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utiles.cpp
)

target_include_directories(
    ${MY_EXECUTABLE_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
