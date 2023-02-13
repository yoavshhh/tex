#pragma once

#include <utility>

typedef std::pair<int, int> pnt;

namespace tex
{

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
#pragma once

#include <utility>

typedef std::pair<int, int> pnt;

namespace tex
{

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
}