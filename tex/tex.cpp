#include "tex.hpp"

namespace tex
{

Tex::Tex() :
    console(Console::getConsole()),
    inputMap({}),
    currentContext(FileContext("")),
    lastPress({0}) { }

Tex::Tex(std::string fileName) :
    console(Console::getConsole()),
    inputMap({}),
    currentContext(FileContext(fileName)),
    lastPress({0}) { }
Tex::Tex() :
    console(Console::getConsole()),
    inputMap({}),
    currentContext(FileContext("")),
    lastPress({0}) { }

Tex::Tex(std::string fileName) :
    console(Console::getConsole()),
    inputMap({}),
    currentContext(FileContext(fileName)),
    lastPress({0}) { }

bool Tex::Init()
{
    // console initialization
    if (!console->Init())
    {
        return false;
    }
    // console initialization
    if (!console->Init())
    {
        return false;
    }
    Press p = {0};

    // up arrow
    p = { .ch = (char)38, .state = KB_NONE };
    this->inputMap.emplace(std::make_pair(p, movePosUp));
    // down arrow
    p = { .ch = (char)40, .state = KB_NONE };
    this->inputMap.emplace(std::make_pair(p, movePosDown));
    // left arrow
    p = { .ch = (char)37, .state = KB_NONE };
    this->inputMap.emplace(std::make_pair(p, movePosLeft));
    // right arrow
    p = { .ch = (char)39, .state = KB_NONE };
    this->inputMap.emplace(std::make_pair(p, movePosRight));

    // enter/return
    p = { .ch = '\r', .state = KB_NONE };
    this->inputMap.emplace(std::make_pair(p, enter));
    // shift + enter/return
    p = { .ch = '\r', .state = KB_SHIFT };
    this->inputMap.emplace(std::make_pair(p, enter));

    // backspace
    p = { .ch = (char)8, .state = KB_NONE };
    this->inputMap.emplace(std::make_pair(p, backspace));


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

    
    return true;
}

void printContent(file_content content)
{
    std::cout << "content:\n" << std::endl;
    for (const auto& obj1 : content) {
        for (const auto& obj2 : obj1) {
            std::cout << obj2;
        }
        std::cout << '\n';
    }
}

void Tex::MainLoop()
{
    while(lastPress.ch != 'A')
    {
        lastPress = Press::getPress();
        system("cls");
        system("cls");
        lastPress.print();
        auto inputPair = inputMap.find(lastPress);
        if (inputPair == inputMap.end())
        {
            std::cout << "couldn't find ";
            lastPress.print();
            continue;
        }
        inputPair->second(*this);
        std::cout << "current pos: " << currentContext.currentPositionIndex << ", and current line: " << currentContext.currentLineIndex << std::endl;
        printContent(currentContext.content);
        if (!console->setCursorPos({currentContext.currentPositionIndex, currentContext.currentLineIndex+5}))
        {
            std::cerr << "didn't work" << std::endl;
        }
        if (!console->setCursorPos({currentContext.currentPositionIndex, currentContext.currentLineIndex+5}))
        {
            std::cerr << "didn't work" << std::endl;
        }
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
