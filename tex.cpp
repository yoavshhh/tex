#include <conio.h>
#include <iostream>

#include "tex.hpp"
#include "actions.hpp"

namespace tex
{

Tex::Tex() : inputMap({}), currentContext(FileContext("")), lastPress({0}) { }
Tex::Tex(std::string fileName) : inputMap({}), currentContext(FileContext(fileName)), lastPress({0}) { }

bool Tex::Init()
{
    for(int i = 32; i <= 126; i++) 
    {
        Press p = {0};
        p.ch = (char)i;
        this->inputMap.insert(std::make_pair(p, insertChar));
    }
    return true;
}

void printContent(file_content content)
{
    std::cout << "content:\n";
    for (const auto& obj1 : content)
        for (const auto& obj2 : obj1)
            std::cout << obj2;
        std::cout << '\n';
}

void Tex::MainLoop()
{
    while(lastPress.ch != 'A')
    {
        int ch = getch();
        lastPress.ch = (char)ch;
        std::function<void(Tex*)> a = inputMap[lastPress];
        a(this);
        printContent(currentContext.content);
    }
}

void Tex::Finish()
{
    // Save file or something
}

Tex::~Tex()
{

}


}
