#pragma once
#define GXX_EXPERIMENTAL_CXX0X
#include <unordered_map>
#include <string>
#include <functional>

#include "press.hpp"
#include "state.hpp"
#include "file_context.hpp"

namespace tex 
{

class Tex {
public:
    std::unordered_map<Press, std::function<void(Tex*)>> inputMap;
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
