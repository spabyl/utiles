#pragma once

/**
 * File: utiles.hpp
 *
 * Current file provides some utilities for console mode.
 * Developed for C++ inspired in RLUTIL.
 * It aims to be cross-platform (Windows, Linux, and macOS).
 *
 * Features:
 * - Console Forecolors
 * - Clear screen
 * - UTF-8 support in Windows
 *
 * Copyright © 2025 Pablo Medina
 * zlib Licence
 *
 */

/// Define: RLUTIL_USE_ANSI
/// Define this to use ANSI escape sequences also on Windows
/// (defaults to using WinAPI instead).
#if 0
#define UTIL_USE_ANSI
#endif

#ifndef UTIL_INLINE
#ifdef _MSC_VER
#define UTIL_INLINE __inline
#else
#define UTIL_INLINE static __inline__
#endif
#endif
namespace ut
{

    UTIL_INLINE void setColor(int c);

    void setBackgroundColor(int c);

    int saveDefaultColor(void);

    UTIL_INLINE void resetColor(void);

    void cls(void);

    UTIL_INLINE void setCursorVisibility(char visible);

    void hidecursor(void);

    void showcursor(void);

    UTIL_INLINE int trows(void);

    UTIL_INLINE int tcols(void);

    void setConsoleTitle(const char *title);

    struct CursorHider;

    void color_white();

    void color_red();

    void color_yellow();

    void color_green();

    void color_magenta();

    void color_grey();

    void color_blue();

    void color_reset();

    void clear();

    void set_title(const char *title);

    void init();

}