#ifdef _WIN32

#include "color_win.hpp"

std::ostream& operator<<(std::ostream& s, std::pair<tex::Color, tex::Color>&& colors)
{
    HANDLE hInput = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD col = 0;
    CONSOLE_SCREEN_BUFFER_INFO i;
    if (colors.first == tex::Color::NONE)   col |= (GetConsoleScreenBufferInfo(hInput, &i) ? i.wAttributes : DEFAULT_COLOR) & 0x0F;
    else                                    col |= static_cast<int>(colors.first);

    if (colors.second == tex::Color::NONE)  col |= (GetConsoleScreenBufferInfo(hInput, &i) ? i.wAttributes : DEFAULT_COLOR) & 0xF0;
    else                                    col |= (static_cast<int>(colors.second) << 4);
    SetConsoleTextAttribute(hInput, col);
    return s;
}

std::ostream& operator<<(std::ostream& s, tex::Color&& c)
{
    HANDLE hInput = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD col = 0;
    CONSOLE_SCREEN_BUFFER_INFO i;
    if (c == tex::Color::NONE)    col |= DEFAULT_COLOR;
    else
    {
        col |= (GetConsoleScreenBufferInfo(hInput, &i) ? i.wAttributes : DEFAULT_COLOR) & 0xF0;
        col |= static_cast<int>(c);
    }

    SetConsoleTextAttribute(hInput, col);
    return s;
}

#endif