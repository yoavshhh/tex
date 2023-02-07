#include "actions.hpp"

namespace tex
{

    void matchCursorPos(Tex &tex)
    {
        if (!tex.console->setCursorPos({tex.currentContext.currentPositionIndex, tex.currentContext.currentLineIndex}))
        {
            std::cerr << "didn't work" << std::endl;
        }
    }

    void clearLine(Tex &tex)
    {
        tex.console->setCursorPos({(*tex.currentContext.currentLine).size(), tex.currentContext.currentLineIndex});
        for(int i = tex.currentContext.currentPositionIndex; i < (int)(*tex.currentContext.currentLine).size(); i++) 
        {
            tex.console->clearCharAtCursor();
        }
    }

    void renderCurrentLine(Tex &tex) 
    {
        clearLine(tex);
        line::iterator it = tex.currentContext.currentPosition; 
        for(int i = tex.currentContext.currentPositionIndex; i < (int)(*tex.currentContext.currentLine).size(); i++) 
        {
            tex.console->insertCharAtCursor(*it);
            it++;
        }
        matchCursorPos(tex);
    }

    void insertChar(Tex &tex)
    {
        tex.currentContext.insertChar(tex.lastPress.ch);
        tex.console->insertCharAtCursor(tex.lastPress.ch);
        // renderCurrentLine(tex);
    }
    void enter(Tex &tex)
    {
        tex.currentContext.enter();
        // std::cout << "a";
    }
    void backspace(Tex &tex)
    {
        tex.currentContext.backspace();
        tex.console->clearCharAtCursor();
        renderCurrentLine(tex);
    }
    void movePosRight(Tex &tex)
    {
        tex.currentContext.movePosRight();
        matchCursorPos(tex);
    }
    void movePosLeft(Tex &tex)
    {
        tex.currentContext.movePosLeft();
        matchCursorPos(tex);
    }
    void movePosUp(Tex &tex)
    {
        tex.currentContext.movePosUp();
        matchCursorPos(tex);
    }
    void movePosDown(Tex &tex)
    {
        tex.currentContext.movePosDown();
        matchCursorPos(tex);
    }

}