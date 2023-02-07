#include "actions.hpp"

namespace tex
{

    // void render(Tex &tex) 
    // {
    //     line::iterator it = tex.currentContext.currentPosition; 
    //     for(int i = tex.currentContext.currentPositionIndex; i < (int)(*tex.currentContext.currentLine).size(); i++) 
    //     {
    //         tex.console->insertCharAtCursor(*it);
    //         it++;
    //     }
    // }

    void insertChar(Tex &tex)
    {
        tex.currentContext.insertChar(tex.lastPress.ch);
        // render(tex);
    }
    void enter(Tex &tex)
    {
        tex.currentContext.enter();
        std::cout << "a";
    }
    void backspace(Tex &tex)
    {
        tex.currentContext.backspace();
    }
    void movePosRight(Tex &tex)
    {
        tex.currentContext.movePosRight();
        if (tex.console->setCursorPos({tex.currentContext.currentPositionIndex, tex.currentContext.currentLineIndex}))
        {
            std::cerr << "didn't work" << std::endl;
        }
    }
    void movePosLeft(Tex &tex)
    {
        tex.currentContext.movePosLeft();
        if (!tex.console->setCursorPos({tex.currentContext.currentPositionIndex, tex.currentContext.currentLineIndex}))
        {
            std::cerr << "didn't work" << std::endl;
        }
    }
    void movePosUp(Tex &tex)
    {
        tex.currentContext.movePosUp();
        if (!tex.console->setCursorPos({tex.currentContext.currentPositionIndex, tex.currentContext.currentLineIndex}))
        {
            std::cerr << "didn't work" << std::endl;
        }
    }
    void movePosDown(Tex &tex)
    {
        tex.currentContext.movePosDown();
        if (!tex.console->setCursorPos({tex.currentContext.currentPositionIndex, tex.currentContext.currentLineIndex}))
        {
            std::cerr << "didn't work" << std::endl;
        }
    }
#include "actions.hpp"

namespace tex
{

    void insertChar(Tex &tex)
    {
        tex.currentContext.insertChar(tex.lastPress.ch);
    }
    void enter(Tex &tex)
    {
        tex.currentContext.enter();
    }
    void backspace(Tex &tex)
    {
        tex.currentContext.backspace();
    }
    void movePosRight(Tex &tex)
    {
        tex.currentContext.movePosRight();
    }
    void movePosLeft(Tex &tex)
    {
        tex.currentContext.movePosLeft();
    }
    void movePosUp(Tex &tex)
    {
        tex.currentContext.movePosUp();
    }
    void movePosDown(Tex &tex)
    {
        tex.currentContext.movePosDown();
    }

}
}