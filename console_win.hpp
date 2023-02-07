#pragma once
#ifdef _WIN32

#include <iostream>
#include <Windows.h>

#include "console.hpp"
#include "color.hpp"

namespace tex
{

class ConsoleWin : public Console{
public:
    virtual bool Init(void);
    virtual bool Destroy(void);

    virtual bool getConsoleSize(pnt& pos);
    virtual bool setConsoleSize(const pnt& pos);

    virtual bool getCursorPos(pnt& pos);
    virtual bool setCursorPos(const pnt& pos);

    virtual bool getConsoleBufferSize(pnt& pos);
    virtual bool setConsoleBufferSize(const pnt& pos);

private:
    HANDLE hInput;
};

}

#endif