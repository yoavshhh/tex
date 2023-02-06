#pragma once
#include <string>
#include <list>

#include "state.hpp"

typedef std::list<char> line;
typedef std::list<line> file_content;


namespace tex
{

class FileContext {
public:
    std::string fileName;
    file_content content;
    line::iterator currentPosition;
    int currentPositionIndex;
    file_content::iterator currentLine;
    int currentLineIndex;
    State state;

    FileContext(std::string fileName);

    void insertChar(char ch);

    void Enter();
};

}
