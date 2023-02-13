#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <list>

#include "../tex/state.hpp"

typedef std::list<char> line;
typedef std::list<line> file_content;


namespace tex
{

class FileContext {
private:
    void matchPosToCurrentLine();
public:
    std::string fileName;
    file_content content;
    file_content::iterator currentLine;
    int currentLineIndex;
    line::iterator currentPosition;
    int currentPositionIndex;
    State state;

    FileContext(std::string fileName);

    void insertChar(char ch);

    void enter();
    void backspace();

    void movePosEnd();
    void movePosStart();
    void movePosRight();
    void movePosLeft();
    void movePosUp();
    void movePosDown();
};

}
