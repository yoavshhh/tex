#pragma once
#include <iostream>
#include <map>

namespace tex
{

#define KB_SHIFT    (1 << 0)
#define KB_CTRL     (1 << 1)
#define KB_ALT      (1 << 2)
    
struct Press {
    char ch;
    char state;

    bool operator ==(const Press& other) const;
};

}

namespace std
{
template<> struct hash<tex::Press> {
    size_t operator()(const tex::Press& press) const;
};
}