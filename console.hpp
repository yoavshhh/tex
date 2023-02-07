#pragma once

#include <utility>

namespace tex
{


typedef std::pair<int, int> pnt;

class Console {
public:
    virtual bool Init(void) = 0;
    virtual bool Destroy(void) = 0;

    virtual bool getConsoleSize(pnt& pos) = 0;
    virtual bool setConsoleSize(const pnt& pos) = 0;

    virtual bool getCursorPos(pnt& pos) = 0;
    virtual bool setCursorPos(const pnt& pos) = 0;

    virtual bool getConsoleBufferSize(pnt& pos) = 0;
    virtual bool setConsoleBufferSize(const pnt& pos) = 0;

    // Factory
    static Console *getConsole(void);
};

}