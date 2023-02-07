#include "file_context.hpp"
#include <iostream>
#include <algorithm>

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
}

void FileContext::backspace()
{
    if(currentLine != content.begin() || currentPosition != (*currentLine).begin())
    {
        if(currentPosition == (*currentLine).begin())
        {
            file_content::iterator preLine = currentLine;
            preLine--;

            currentPositionIndex = (*preLine).size();
            currentPosition = (*preLine).end();
            currentPosition--;

            (*preLine).splice((*preLine).end(), *currentLine);
            content.erase(currentLine);
            currentLine = preLine;
            currentLineIndex--;
            currentPosition++;
        }
        else
        {
            line::iterator it = currentPosition;
            (*currentLine).erase(--currentPosition);
            currentPosition = it;
            currentPositionIndex--;
        }
    }
}

void FileContext::enter() 
{
    line newLine = {};
    newLine.splice(newLine.begin(), *currentLine, currentPosition, (*currentLine).end());
    if(currentLineIndex == content.size() - 1) {
        content.insert(content.end(), newLine);
        currentLine = --content.end();
    }
    else {
        currentLine++;
        content.emplace(currentLine,  newLine);
        currentLine--;
    }
    currentLineIndex++;
    currentPosition = (*currentLine).begin();
    currentPositionIndex = 0;
}

void FileContext::movePosRight()
{
    if( currentPositionIndex < (*currentLine).size())
    {
        currentPosition++;
        currentPositionIndex++;
    }
}
void FileContext::movePosLeft()
{
    if(currentPositionIndex > 0)
    {
        currentPosition--;
        currentPositionIndex--;
    }
}
void FileContext::movePosUp()
{
    if(currentLineIndex > 0)
    {
        currentLine--;
        currentLineIndex--;
        matchPosToCurrentLine();
    }
}
void FileContext::movePosDown()
{
    if(currentLineIndex < content.size() - 1)
    {
        currentLine++;
        currentLineIndex++;
        matchPosToCurrentLine();
    }
}

void FileContext::matchPosToCurrentLine()
{
    currentPosition = (*currentLine).begin();
    currentPositionIndex = std::min(currentPositionIndex, (int)(*currentLine).size());
    std::advance(currentPosition, currentPositionIndex);
}

}