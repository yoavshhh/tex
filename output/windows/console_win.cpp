#ifdef _WIN32

#include "console_win.hpp"

namespace tex
{

ConsoleWin::ConsoleWin()
{
    hConsoleBuffer = CreateConsoleScreenBuffer(
       GENERIC_READ |           // read/write access
       GENERIC_WRITE,
       FILE_SHARE_READ |
       FILE_SHARE_WRITE,        // shared
       NULL,                    // default security attributes
       CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE
       NULL);                   // reserved; must be NULL
       
    if (hConsoleBuffer == INVALID_HANDLE_VALUE)
    {
        std::cerr << "CreateConsoleScreenBuffer failed - " << GetLastError() << std:: endl;
    }

    outBuff = new OutBuffer(hConsoleBuffer);
}

ConsoleWin::~ConsoleWin() 
{
    delete outBuff;
}

bool ConsoleWin::Init(void)
{
    // setup console buffer
    pnt sz;
    if (!getConsoleSize(sz))
    {
        std::cerr << "getConsoleSize failed - " << GetLastError() << std:: endl;
        return false;
    }
    if (!setConsoleBufferSize(sz))
    {
        std::cerr << "setConsoleBufferSize failed - " << GetLastError() << std:: endl;
        return false;
    }
    if (!SetConsoleActiveScreenBuffer(hConsoleBuffer) )
    {
        std::cerr << "SetConsoleActiveScreenBuffer failed - " << GetLastError() << std:: endl;
        return false;
    }

    std::cout.rdbuf(outBuff);

    std::cout << Color::NONE;
    
    return true;
}

bool ConsoleWin::Destroy(void)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (! SetConsoleActiveScreenBuffer(hStdout) )
    {
        std::cerr << "SetConsoleActiveScreenBuffer failed - " << GetLastError() << std:: endl;
        return false;
    }

    return true;
}

bool ConsoleWin::getConsoleSize(pnt& pos)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hConsoleBuffer, &info))
    {
        return false;
    }
    pos.first = info.dwMaximumWindowSize.X;
    pos.second = info.dwMaximumWindowSize.Y;
    return true;
}

bool ConsoleWin::setConsoleSize(const pnt& pos)
{
    return true;
}

bool ConsoleWin::getCursorPos(pnt& pos)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hConsoleBuffer, &info))
    {
        return false;
    }
    pos.first = info.dwCursorPosition.X;
    pos.second = info.dwCursorPosition.Y;
    return true;
}
bool ConsoleWin::setCursorPos(const pnt& pos)
{
    return SetConsoleCursorPosition(hConsoleBuffer, { (short)pos.first, (short)pos.second });
}

bool ConsoleWin::getConsoleBufferSize(pnt& pos)
{
    return true;
}

bool ConsoleWin::setConsoleBufferSize(const pnt& pos)
{
    return SetConsoleScreenBufferSize(hConsoleBuffer, { (short)pos.first, (short)pos.second });
}

}

#endif
#ifdef _WIN32

#include "console_win.hpp"

namespace tex
{

ConsoleWin::ConsoleWin()
{
    hConsoleBuffer = CreateConsoleScreenBuffer(
       GENERIC_READ |           // read/write access
       GENERIC_WRITE,
       FILE_SHARE_READ |
       FILE_SHARE_WRITE,        // shared
       NULL,                    // default security attributes
       CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE
       NULL);                   // reserved; must be NULL
       
    if (hConsoleBuffer == INVALID_HANDLE_VALUE)
    {
        std::cerr << "CreateConsoleScreenBuffer failed - " << GetLastError() << std:: endl;
    }

    outBuff = new OutBuffer(hConsoleBuffer);
}

ConsoleWin::~ConsoleWin() 
{
    delete outBuff;
}

bool ConsoleWin::Init(void)
{
    // setup console buffer
    pnt sz;
    if (!getConsoleSize(sz))
    {
        std::cerr << "getConsoleSize failed - " << GetLastError() << std:: endl;
        return false;
    }
    if (!setConsoleBufferSize(sz))
    {
        std::cerr << "setConsoleBufferSize failed - " << GetLastError() << std:: endl;
        return false;
    }
    if (!SetConsoleActiveScreenBuffer(hConsoleBuffer) )
    {
        std::cerr << "SetConsoleActiveScreenBuffer failed - " << GetLastError() << std:: endl;
        return false;
    }

    std::cout.rdbuf(outBuff);

    std::cout << Color::NONE;
    
    return true;
}

bool ConsoleWin::Destroy(void)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (! SetConsoleActiveScreenBuffer(hStdout) )
    {
        std::cerr << "SetConsoleActiveScreenBuffer failed - " << GetLastError() << std:: endl;
        return false;
    }

    return true;
}

bool ConsoleWin::getConsoleSize(pnt& pos)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hConsoleBuffer, &info))
    {
        return false;
    }
    pos.first = info.dwMaximumWindowSize.X;
    pos.second = info.dwMaximumWindowSize.Y;
    return true;
}

bool ConsoleWin::setConsoleSize(const pnt& pos)
{
    return true;
}

bool ConsoleWin::getCursorPos(pnt& pos)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hConsoleBuffer, &info))
    {
        return false;
    }
    pos.first = info.dwCursorPosition.X;
    pos.second = info.dwCursorPosition.Y;
    return true;
}
bool ConsoleWin::setCursorPos(const pnt& pos)
{
    return SetConsoleCursorPosition(hConsoleBuffer, { (short)pos.first, (short)pos.second });
}

bool ConsoleWin::getConsoleBufferSize(pnt& pos)
{
    return true;
}

bool ConsoleWin::setConsoleBufferSize(const pnt& pos)
{
    return SetConsoleScreenBufferSize(hConsoleBuffer, { (short)pos.first, (short)pos.second });
}

}

#endif