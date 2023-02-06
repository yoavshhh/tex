#include "file_context.hpp"
#include <iostream>

namespace tex
{

FileContext::FileContext(std::string fileName) : fileName(fileName),
                                                 content({{}}),
                                                 currentLine(content.begin()),
                                                 currentLineIndex(0),
                                                 currentPosition((*content.begin()).begin()),
                                                 currentPositionIndex(0),
                                                 state(State::INSERT) { }

void FileContext::insertChar(char ch)
{
    (*currentLine).emplace(currentPosition, ch);
    currentPositionIndex++;
    std::cout << "current pos: " << currentPositionIndex << ", and current line: " << currentLineIndex << std::endl;
}

void FileContext::Enter() 
{
    (*currentLine).emplace(currentPosition, '\n');
    currentPositionIndex++;
    content.push_back({});
    currentLine = content.end();
    currentLineIndex = content.size();
    std::cout << "current pos: " << currentPositionIndex << ", and current line: " << currentLineIndex << std::endl;
}

}