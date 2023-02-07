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
    if (! SetConsoleActiveScreenBuffer(hConsoleBuffer) )
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

}
bool ConsoleWin::setConsoleSize(const pnt& pos)
{

}

bool ConsoleWin::getCursorPos(pnt& pos)
{

}
bool ConsoleWin::setCursorPos(const pnt& pos)
{

}

bool ConsoleWin::getConsoleBufferSize(pnt& pos)
{

}
bool ConsoleWin::setConsoleBufferSize(const pnt& pos)
{

}

}

#endif