#pragma once
#ifdef _WIN32

#include <iostream>
#include <Windows.h>

    
#include "../console.hpp"
#include "../colors/color.hpp"
#include "out_buffer.hpp"

typedef std::pair<int, int> pnt;

namespace tex
{

class ConsoleWin : public Console {
public:
    ConsoleWin();
    ~ConsoleWin();

    bool Init(void);
    bool Destroy(void);

    bool getConsoleSize(pnt& pos);
    bool setConsoleSize(const pnt& pos);

    bool getCursorPos(pnt& pos);
    bool setCursorPos(const pnt& pos);

    bool getConsoleBufferSize(pnt& pos);
    bool setConsoleBufferSize(const pnt& pos);

    // void insertCharAtCursor(char ch);
    // void clearCharAtCursor();

private:
    HANDLE hConsoleBuffer;
    OutBuffer *outBuff;
};

}

#endif
#pragma once
#ifdef _WIN32

#include <iostream>
#include <Windows.h>

    
#include "../console.hpp"
#include "../colors/color.hpp"
#include "out_buffer.hpp"

typedef std::pair<int, int> pnt;

namespace tex
{

class ConsoleWin : public Console {
public:
    ConsoleWin();
    ~ConsoleWin();

    bool Init(void);
    bool Destroy(void);

    bool getConsoleSize(pnt& pos);
    bool setConsoleSize(const pnt& pos);

    bool getCursorPos(pnt& pos);
    bool setCursorPos(const pnt& pos);

    bool getConsoleBufferSize(pnt& pos);
    bool setConsoleBufferSize(const pnt& pos);

private:
    HANDLE hConsoleBuffer;
    OutBuffer *outBuff;
};

}

#endif