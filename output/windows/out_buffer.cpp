#include "out_buffer.hpp"

namespace tex
{

OutBuffer::OutBuffer(HANDLE h) : h(h) {}

std::streambuf::int_type OutBuffer::overflow(int_type c) {
    if (c != EOF) {
        DWORD written;
        WriteConsole(h, &c, 1, &written, nullptr);
    }
    return c;
}

std::streamsize OutBuffer::xsputn(char_type const *s, std::streamsize count) {
    DWORD written;
    WriteConsole(h, s, count, &written, nullptr);
    return written;
}

};

