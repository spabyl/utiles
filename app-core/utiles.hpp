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

#include <cassert>
#include <cinttypes>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cstdio> // for getch()
#include <iostream>

#define _VERSION_ "version 0.0.1.-alpha"

#ifdef _WIN32
#include <windows.h> // for WinAPI and Sleep()
#define _NO_OLDNAMES // for MinGW compatibility
#include <conio.h>   // for getch() and kbhit()
#define getch _getch
#define kbhit _kbhit
#else
#include <sys/ioctl.h> // for getkey()
#include <sys/time.h>  // for kbhit()
#include <sys/types.h> // for kbhit()
#include <termios.h>   // for getch() and kbhit()
#include <unistd.h>    // for getch(), kbhit() and (u)sleep()
#endif

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

/**
 * Enums: Color codes
 *
 * BLACK - Black
 * BLUE - Blue
 * GREEN - Green
 * CYAN - Cyan
 * RED - Red
 * MAGENTA - Magenta / purple
 * BROWN - Brown / dark yellow
 * GREY - Grey / dark white
 * DARKGREY - Dark grey / light black
 * LIGHTBLUE - Light blue
 * LIGHTGREEN - Light green
 * LIGHTCYAN - Light cyan
 * LIGHTRED - Light red
 * LIGHTMAGENTA - Light magenta / light purple
 * YELLOW - Yellow (bright)
 * WHITE - White (bright)
 */
enum class Color : int
{
    BLACK = 0,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARKGREY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

/**
 * Consts: ANSI escape strings
 *
 * ANSI_CLS                - Clears screen
 * ANSI_CONSOLE_TITLE_PRE  - Prefix for changing the window title, print the
 * window title in between ANSI_CONSOLE_TITLE_POST - Suffix for changing the
 * window title, print the window title in between ANSI_ATTRIBUTE_RESET    -
 * Resets all attributes ANSI_CURSOR_HIDE        - Hides the cursor
 * ANSI_CURSOR_SHOW        - Shows the cursor
 * ANSI_BLACK              - Black
 * ANSI_RED                - Red
 * ANSI_GREEN              - Green
 * ANSI_BROWN              - Brown / dark yellow
 * ANSI_BLUE               - Blue
 * ANSI_MAGENTA            - Magenta / purple
 * ANSI_CYAN               - Cyan
 * ANSI_GREY               - Grey / dark white
 * ANSI_DARKGREY           - Dark grey / light black
 * ANSI_LIGHTRED           - Light red
 * ANSI_LIGHTGREEN         - Light green
 * ANSI_YELLOW             - Yellow (bright)
 * ANSI_LIGHTBLUE          - Light blue
 * ANSI_LIGHTMAGENTA       - Light magenta / light purple
 * ANSI_LIGHTCYAN          - Light cyan
 * ANSI_WHITE              - White (bright)
 * ANSI_BACKGROUND_BLACK   - Black background
 * ANSI_BACKGROUND_RED     - Red background
 * ANSI_BACKGROUND_GREEN   - Green background
 * ANSI_BACKGROUND_YELLOW  - Yellow background
 * ANSI_BACKGROUND_BLUE    - Blue background
 * ANSI_BACKGROUND_MAGENTA - Magenta / purple background
 * ANSI_BACKGROUND_CYAN    - Cyan background
 * ANSI_BACKGROUND_WHITE   - White background
 */

/*
const RLUTIL_STRING_T ANSI_CLS = "\033[2J\033[3J";
const RLUTIL_STRING_T ANSI_CONSOLE_TITLE_PRE = "\033]0;";
const RLUTIL_STRING_T ANSI_CONSOLE_TITLE_POST = "\007";
const RLUTIL_STRING_T ANSI_ATTRIBUTE_RESET = "\033[0m";
const RLUTIL_STRING_T ANSI_CURSOR_HIDE = "\033[?25l";
const RLUTIL_STRING_T ANSI_CURSOR_SHOW = "\033[?25h";
const RLUTIL_STRING_T ANSI_CURSOR_HOME = "\033[H";
const RLUTIL_STRING_T ANSI_BLACK = "\033[22;30m";
const RLUTIL_STRING_T ANSI_RED = "\033[22;31m";
const RLUTIL_STRING_T ANSI_GREEN = "\033[22;32m";
const RLUTIL_STRING_T ANSI_BROWN = "\033[22;33m";
const RLUTIL_STRING_T ANSI_BLUE = "\033[22;34m";
const RLUTIL_STRING_T ANSI_MAGENTA = "\033[22;35m";
const RLUTIL_STRING_T ANSI_CYAN = "\033[22;36m";
const RLUTIL_STRING_T ANSI_GREY = "\033[22;37m";
const RLUTIL_STRING_T ANSI_DARKGREY = "\033[01;30m";
const RLUTIL_STRING_T ANSI_LIGHTRED = "\033[01;31m";
const RLUTIL_STRING_T ANSI_LIGHTGREEN = "\033[01;32m";
const RLUTIL_STRING_T ANSI_YELLOW = "\033[01;33m";
const RLUTIL_STRING_T ANSI_LIGHTBLUE = "\033[01;34m";
const RLUTIL_STRING_T ANSI_LIGHTMAGENTA = "\033[01;35m";
const RLUTIL_STRING_T ANSI_LIGHTCYAN = "\033[01;36m";
const RLUTIL_STRING_T ANSI_WHITE = "\033[01;37m";
const RLUTIL_STRING_T ANSI_BACKGROUND_BLACK = "\033[40m";
const RLUTIL_STRING_T ANSI_BACKGROUND_RED = "\033[41m";
const RLUTIL_STRING_T ANSI_BACKGROUND_GREEN = "\033[42m";
const RLUTIL_STRING_T ANSI_BACKGROUND_YELLOW = "\033[43m";
const RLUTIL_STRING_T ANSI_BACKGROUND_BLUE = "\033[44m";
const RLUTIL_STRING_T ANSI_BACKGROUND_MAGENTA = "\033[45m";
const RLUTIL_STRING_T ANSI_BACKGROUND_CYAN = "\033[46m";
const RLUTIL_STRING_T ANSI_BACKGROUND_WHITE = "\033[47m";
// Remaining colors not supported as background colors

RLUTIL_INLINE RLUTIL_STRING_T getANSIColor(const int c)
{
   switch (c)
   {
   case BLACK:
       return ANSI_BLACK;
   case BLUE:
       return ANSI_BLUE; // non-ANSI
   case GREEN:
       return ANSI_GREEN;
   case CYAN:
       return ANSI_CYAN; // non-ANSI
   case RED:
       return ANSI_RED; // non-ANSI
   case MAGENTA:
       return ANSI_MAGENTA;
   case BROWN:
       return ANSI_BROWN;
   case GREY:
       return ANSI_GREY;
   case DARKGREY:
       return ANSI_DARKGREY;
   case LIGHTBLUE:
       return ANSI_LIGHTBLUE; // non-ANSI
   case LIGHTGREEN:
       return ANSI_LIGHTGREEN;
   case LIGHTCYAN:
       return ANSI_LIGHTCYAN; // non-ANSI;
   case LIGHTRED:
       return ANSI_LIGHTRED; // non-ANSI;
   case LIGHTMAGENTA:
       return ANSI_LIGHTMAGENTA;
   case YELLOW:
       return ANSI_YELLOW; // non-ANSI
   case WHITE:
       return ANSI_WHITE;
   default:
       return "";
   }
}

/// Function: getANSIBackgroundColor
/// Return ANSI background color escape sequence for specified number 0-15.
///
/// See <Color Codes>
RLUTIL_INLINE RLUTIL_STRING_T getANSIBackgroundColor(const int c)
{
   switch (c)
   {
   case BLACK:
       return ANSI_BACKGROUND_BLACK;
   case BLUE:
       return ANSI_BACKGROUND_BLUE;
   case GREEN:
       return ANSI_BACKGROUND_GREEN;
   case CYAN:
       return ANSI_BACKGROUND_CYAN;
   case RED:
       return ANSI_BACKGROUND_RED;
   case MAGENTA:
       return ANSI_BACKGROUND_MAGENTA;
   case BROWN:
       return ANSI_BACKGROUND_YELLOW;
   case GREY:
       return ANSI_BACKGROUND_WHITE;
   default:
       return "";
   }
}
*/
/// Function: setColor
/// Change color specified by number (Windows / QBasic colors).
/// Don't change the background color
///
/// See <Color Codes>
RLUTIL_INLINE void setColor(int c)
{
#if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);

    SetConsoleTextAttribute(
        hConsole,
        (csbi.wAttributes & 0xFFF0) |
            (WORD)c); // Foreground colors take up the least significant byte
#else
    RLUTIL_PRINT(getANSIColor(c));
#endif
}

/// Function: setBackgroundColor
/// Change background color specified by number (Windows / QBasic colors).
/// Don't change the foreground color
///
/// See <Color Codes>
void setBackgroundColor(int c)
{
#if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);

    SetConsoleTextAttribute(
        hConsole, (csbi.wAttributes & 0xFF0F) |
                      (((WORD)c) << 4)); // Background colors take up the
                                         // second-least significant byte
#else
    RLUTIL_PRINT(getANSIBackgroundColor(c));
#endif
}

/// Function: saveDefaultColor
/// Call once to preserve colors for use in resetColor()
/// on Windows without ANSI, no-op otherwise
///
/// See <Color Codes>
/// See <resetColor>
int saveDefaultColor(void)
{
#if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
    static char initialized = 0; // bool
    static WORD attributes;

    if (!initialized)
    {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        attributes = csbi.wAttributes;
        initialized = 1;
    }
    return (int)attributes;
#else
    return -1;
#endif
}

/// Function: resetColor
/// Reset color to default
/// Requires a call to saveDefaultColor() to set the defaults
///
/// See <Color Codes>
/// See <setColor>
/// See <saveDefaultColor>
RLUTIL_INLINE void resetColor(void)
{
#if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            (WORD)saveDefaultColor());
#else
    RLUTIL_PRINT(ANSI_ATTRIBUTE_RESET);
#endif
}

/// Function: cls
/// Clears screen, resets all attributes and moves cursor home.
void cls(void)
{
#if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
    // Based on
    // https://msdn.microsoft.com/en-us/library/windows/desktop/ms682022%28v=vs.85%29.aspx
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const COORD coordScreen = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    const DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen,
                               &cCharsWritten);

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen,
                               &cCharsWritten);

    SetConsoleCursorPosition(hConsole, coordScreen);
#else
    RLUTIL_PRINT(ANSI_CLS);
    RLUTIL_PRINT(ANSI_CURSOR_HOME);
#endif
}
/*
#if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD numberOfCharsWritten;
CONSOLE_SCREEN_BUFFER_INFO csbi;

GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
WriteConsoleOutputCharacterA(hConsoleOutput, str, len, csbi.dwCursorPosition,
                             &numberOfCharsWritten);
#else // _WIN32 || USE_ANSI
RLUTIL_PRINT(str);
#ifdef __cplusplus
RLUTIL_PRINT("\033[" << len << 'D');
#else // __cplusplus
*/
/// Function: setCursorVisibility
/// Shows/hides the cursor.
RLUTIL_INLINE void setCursorVisibility(char visible)
{
#if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsoleOutput,
                         &structCursorInfo); // Get current cursor size
    structCursorInfo.bVisible = (visible ? TRUE : FALSE);
    SetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
#else  // _WIN32 || USE_ANSI
    RLUTIL_PRINT((visible ? ANSI_CURSOR_SHOW : ANSI_CURSOR_HIDE));
#endif // _WIN32 || USE_ANSI
}

/// Function: hidecursor
/// Hides the cursor.
void hidecursor(void) { setCursorVisibility(0); }

/// Function: showcursor
/// Shows the cursor.
void showcursor(void) { setCursorVisibility(1); }

/// Function: trows
/// Get the number of rows in the terminal window or -1 on error.
RLUTIL_INLINE int trows(void)
{
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return -1;
    else
        return csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // Window height
                                                             // return csbi.dwSize.Y; // Buffer height
#else
#ifdef TIOCGSIZE
    struct ttysize ts;
    ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
    return ts.ts_lines;
#elif defined(TIOCGWINSZ)
    struct winsize ts;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
    return ts.ws_row;
#else  // TIOCGSIZE
    return -1;
#endif // TIOCGSIZE
#endif // _WIN32
}

/// Function: tcols
/// Get the number of columns in the terminal window or -1 on error.
RLUTIL_INLINE int tcols(void)
{
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return -1;
    else
        return csbi.srWindow.Right - csbi.srWindow.Left + 1; // Window width
                                                             // return csbi.dwSize.X; // Buffer width
#else
#ifdef TIOCGSIZE
    struct ttysize ts;
    ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
    return ts.ts_cols;
#elif defined(TIOCGWINSZ)
    struct winsize ts;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
    return ts.ws_col;
#else  // TIOCGSIZE
    return -1;
#endif // TIOCGSIZE
#endif // _WIN32
}

/// Function: anykey
/// Waits until a key is pressed.
/// In C++, it either takes no arguments
/// or a template-type-argument-deduced
/// argument.
/// In C, it takes a const char* representing
/// the message to be displayed, or NULL
/// for no message.

void setConsoleTitle(const char *title)
{
    const char *true_title = title;

#if defined(_WIN32) // && !defined(RLUTIL_USE_ANSI)
    SetConsoleTitleA(title);
#else
    RLUTIL_PRINT(ANSI_CONSOLE_TITLE_PRE);
    RLUTIL_PRINT(true_title);
    RLUTIL_PRINT(ANSI_CONSOLE_TITLE_POST);
#endif // defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
}

// Classes are here at the end so that documentation is pretty.

/// Class: CursorHider
/// RAII OOP wrapper for <rlutil.hidecursor>.
/// Hides the cursor and shows it again
/// when the object goes out of scope.
struct CursorHider
{
    CursorHider() { hidecursor(); }
    ~CursorHider() { showcursor(); }
};

void color_white() { setColor(static_cast<int>(Color::WHITE)); }

void color_red() { setColor(static_cast<int>(Color::LIGHTRED)); }

void color_yellow() { setColor(static_cast<int>(Color::YELLOW)); }

void color_green() { setColor(static_cast<int>(Color::GREEN)); }

void color_magenta() { setColor(static_cast<int>(Color::MAGENTA)); }

void color_grey() { setColor(static_cast<int>(Color::GREY)); }

void color_blue() { setColor(static_cast<int>(Color::BLUE)); }

// void color_reset() { resetColor(); } // this doesn't work!

void color_reset() // this work!
{
    setColor(static_cast<int>(Color::WHITE));
    setBackgroundColor(static_cast<int>(Color::BLACK));
}

void clear() { cls(); }

void set_title(const char *title) { setConsoleTitle(title); }

#ifdef _WIN32
void init()
{
    // Establece el color y el modo UTF-8 en Windows
    color_white();
    SetConsoleOutputCP(CP_UTF8); // Cambiar STDOUT - Para máquinas Windows
    // limpia la consola
    clear();
}
#else
void init()
{
    // Establece el color en otros sistemas
    color_white();
    // limpia la consola
    clear();
}
#endif
