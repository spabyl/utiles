#pragma once

#ifdef DLL_EXPORTS
    #ifdef _WIN32
        #ifdef DLL_EXPORTS
            #define _DLL_API __declspec(dllexport)
        #else
            #define _DLL_API __declspec(dllimport)
        #endif
    #else
        #define _DLL_API
    #endif
#else
    #define _DLL_API
#endif
