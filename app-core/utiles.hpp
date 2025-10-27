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
#define RLUTIL_USE_ANSI
#endif

#ifndef RLUTIL_INLINE
#ifdef _MSC_VER
#define RLUTIL_INLINE __inline
#else
#define RLUTIL_INLINE static __inline__
#endif
#endif
namespace ut
{

    RLUTIL_INLINE void setColor(int c);

    void setBackgroundColor(int c);

    int saveDefaultColor(void);

    RLUTIL_INLINE void resetColor(void);

    void cls(void);

    RLUTIL_INLINE void setCursorVisibility(char visible);

    void hidecursor(void);

    void showcursor(void);

    RLUTIL_INLINE int trows(void);

    RLUTIL_INLINE int tcols(void);

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