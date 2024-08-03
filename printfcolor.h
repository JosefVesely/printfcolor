#ifndef PRINTFCOLOR_H
#define PRINTFCOLOR_H

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

// #undef _WIN32 // TESTING FOR UNIX!!!

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


typedef enum {
    GRAY = 0,
    GREY = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    YELLOW = 6,
    WHITE = 7
} Color;

int printfColor(Color foregroundColor, Color backgroundColor, const char *format, ...);
int printfColorFg(Color foregroundColor, const char *format, ...);
int printfColorBg(Color backgroundColor, const char *format, ...);


// Helper functions

const char* getForegroundColorCode(Color color) {
    switch (color) {
        case GRAY:    return "\033[30m";
        case BLUE:    return "\033[34m";
        case GREEN:   return "\033[32m";
        case CYAN:    return "\033[36m";
        case RED:     return "\033[31m";
        case MAGENTA: return "\033[35m";
        case YELLOW:  return "\033[33m";
        case WHITE:   return "\033[37m";
        default:      return NULL; // Return NULL for invalid colors
    }
}

const char* getBackgroundColorCode(Color color) {
    switch (color) {
        case GRAY:    return "\033[40m";
        case BLUE:    return "\033[44m";
        case GREEN:   return "\033[42m";
        case CYAN:    return "\033[46m";
        case RED:     return "\033[41m";
        case MAGENTA: return "\033[45m";
        case YELLOW:  return "\033[43m";
        case WHITE:   return "\033[47m";
        default:      return NULL; // Return NULL for invalid colors
    }
}

bool isColorCodeValid(Color color)
{
    return color >= 0 && color <= 7;
}

#ifdef _WIN32 // Windows

int printfColor(Color foregroundColor, Color backgroundColor, const char *format, ...) 
{
    if (!isColorCodeValid(foregroundColor) || !isColorCodeValid(backgroundColor)) {
        fprintf(stderr, "Error: Invalid color\n");
        return -1;
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        fprintf(stderr, "Error: Could not retrieve console screen buffer info\n");
        return -1;
    }

    va_list args;
    va_start(args, format);

    SetConsoleTextAttribute(hConsole, foregroundColor | (backgroundColor << 4));
    int charsWritten = vprintf(format, args);
    SetConsoleTextAttribute(hConsole, csbi.wAttributes);

    va_end(args);

    return charsWritten;
}

int printfColorFg(Color foregroundColor, const char *format, ...) 
{
    if (!isColorCodeValid(foregroundColor)) {
        fprintf(stderr, "Error: Invalid color\n");
        return -1;
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        fprintf(stderr, "Error: Could not retrieve console screen buffer info\n");
    }

    va_list args;
    va_start(args, format);

    SetConsoleTextAttribute(hConsole, foregroundColor);

    int charsWritten = vprintf(format, args);

    SetConsoleTextAttribute(hConsole, csbi.wAttributes);

    va_end(args);

    return charsWritten;
}

int printfColorBg(Color backgroundColor, const char *format, ...) 
{
    if (!isColorCodeValid(backgroundColor)) {
        fprintf(stderr, "Error: Invalid color\n");
        return -1;
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        fprintf(stderr, "Error: Could not retrieve console screen buffer info\n");
        return -1;
    }

    va_list args;
    va_start(args, format);

    SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0x0F) | (backgroundColor << 4));
    int charsWritten = vprintf(format, args);
    SetConsoleTextAttribute(hConsole, csbi.wAttributes);

    va_end(args);

    return charsWritten;
}

#else // Linux and Unix-like

int printfColor(Color foregroundColor, Color backgroundColor, const char *format, ...)
{
    if (!isColorCodeValid(foregroundColor) || !isColorCodeValid(backgroundColor)) {
        fprintf(stderr, "Error: Invalid color\n");
        return -1;
    }

    printf("%s%s", getForegroundColorCode(foregroundColor), getBackgroundColorCode(backgroundColor));

    va_list args;
    va_start(args, format);

    int charsWritten = vprintf(format, args);
    printf("\033[0m");

    va_end(args);

    return charsWritten;
}

int printfColorFg(Color foregroundColor, const char *format, ...) 
{
    if (!isColorCodeValid(foregroundColor)) {
        fprintf(stderr, "Error: Invalid color\n");
        return -1;
    }

    printf("%s", getForegroundColorCode(foregroundColor));

    va_list args;
    va_start(args, format);

    int charsWritten = vprintf(format, args);
    printf("\033[0m");

    va_end(args);

    return charsWritten;
}

int printfColorBg(Color backgroundColor, const char *format, ...) 
{
    if (!isColorCodeValid(backgroundColor)) {
        fprintf(stderr, "Error: Invalid color\n");
        return -1;
    }

    printf("%s", getBackgroundColorCode(backgroundColor));

    va_list args;
    va_start(args, format);

    int charsWritten = vprintf(format, args);
    printf("\033[0m");

    va_end(args);

    return charsWritten;
}

#endif // _WIN32

#ifdef __cplusplus
}
#endif

#endif // PRINTFCOLOR_H