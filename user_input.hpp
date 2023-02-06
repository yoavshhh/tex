#pragma once

#include <iostream>

#define KB_SHIFT    (1 << 0)
#define KB_CTRL     (1 << 1)
#define KB_ALT      (1 << 2)
#define KB_NUMLOCK  (1 << 3)
#define KB_CAPSLOCK (1 << 4)

struct Press {
    char ch;
    char state;

    void print() {
        std::cout << "ch: " << (int)ch << " | " << ch << std::endl <<
            "state: " << (int)state << std::endl;
    }

    static void Init();
    static Press getPress();
};
