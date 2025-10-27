#pragma once

/** exampled doc
 ** @author PCMA-SOFT
 ** @file logger.hpp
 ** @brief Logger utility functions for console applications.
 ** @version 1.0
 ** @date 2025-09-06
 
 ** This header file provides utility functions for logging messages to the console with different colors and formats.
 ** It includes functions to set text colors, log messages with timestamps, and manage console output.
 ** @see app-core/tests/main_test.cpp for usage examples.
 
 #ifdef ION_LOG_LEVEL_DEBUG
    #define LOGD(x) \
        ion::log::Logger(ion::log::Message::MSGDEBUG,__FILE__, __LINE__).Log(x)
    #else
        define TLOGD(x) if (true) {} else std::cerr << x << std::endl;
    #endif
    #ifdef ION_LOG_LEVEL_INFO
    #define LOGI(x) \
        ion::log::Logger(ion::log::Message::MSGINFO,__FILE__, __LINE__).Log(x)
    #else
        define TLOGI(x) if (true) {} else std::cerr << x << std::endl;
    #endif
    #ifdef ION_LOG_LEVEL_WARNING
    #define LOGW(x) \
        ion::log::Logger(ion::log::Message::MSGWARNING,__FILE__, __LINE__).Log(x)
    #else
        define TLOGW(x) if (true) {} else std::cerr << x << std::endl;
    #endif
    #ifdef ION_LOG_LEVEL_ERROR
    #define LOGE(x) \
        ion::log::Logger(ion::log::Message::MSGERROR,__FILE__, __LINE__).Log(x) 
    #else
        define TLOGE(x) if (true) {} else std::cerr << x << std::endl;
    #endif
    #ifdef ION_LOG_LEVEL_FATAL
    #define LOGF(x) \
        ion::log::Logger(ion::log::Message::MSGFATAL,__FILE__, __LINE__).Log(x)
    #else
        define TLOGF(x) if (true) {} else std::cerr << x << std::endl;
    #endif

   
    *** OBS: this macro only works in debug mode ..
 */
