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