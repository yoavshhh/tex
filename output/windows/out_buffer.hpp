#pragma once

#include <windows.h>
#include <iostream>

namespace tex
{

class OutBuffer : public std::streambuf {
    HANDLE h;
public:
    OutBuffer(HANDLE h);
protected:
    virtual int_type overflow(int_type c);

    virtual std::streamsize xsputn(char_type const *s, std::streamsize count);
};

}

