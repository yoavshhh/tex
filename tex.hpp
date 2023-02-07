#pragma once
#define GXX_EXPERIMENTAL_CXX0X
#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
#include <conio.h>

#include "user_input.hpp"
#include "state.hpp"
#include "file_context.hpp"
#include "actions.hpp"
#include "console.hpp"
#include "color.hpp"

namespace tex 
{

class Tex {
public:
    Console *console;
    std::unordered_map<Press, std::function<void(Tex&)>> inputMap;
    FileContext currentContext;
    Press lastPress; // in future - stack of last presses to enable restore

    Tex();
    Tex(std::string fileName);

    bool Init();
    void MainLoop();
    void Finish();

    ~Tex();
};

}
