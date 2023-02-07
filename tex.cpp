#include "tex.hpp"

namespace tex
{

Tex::Tex() : inputMap({}), currentContext(FileContext("")), lastPress({0}) { }
Tex::Tex(std::string fileName) : inputMap({}), currentContext(FileContext(fileName)), lastPress({0}) { }

bool Tex::Init()
{
    Press p = {0};
    // mapping all printable ascii letters with clear state
    for(char ch = 32; ch <= 126; ch++) 
    {
        p = { .ch = ch, .state = KB_NONE };
        this->inputMap.insert(std::make_pair(p, insertChar));
    }
    // mapping all printable ascii letters with shift state
    for(char ch = 32; ch <= 126; ch++) 
    {
        p = { .ch = ch, .state = KB_SHIFT };
        this->inputMap.emplace(std::make_pair(p, insertChar));
    }

    // enter/return
    p = { .ch = '\r', .state = KB_NONE };
    this->inputMap.emplace(std::make_pair(p, enter));
    // shift + enter/return
    p = { .ch = '\r', .state = KB_SHIFT };
    this->inputMap.emplace(std::make_pair(p, enter));
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
        lastPress = Press::getPress();
        system("clear");
        auto inputPair = inputMap.find(lastPress);
        if (inputPair == inputMap.end())
        {
            std::cout << "couldn't find ";
            lastPress.print();
            continue;
        }
        inputPair->second(*this);
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
