#include "actions.hpp"

namespace tex
{

    // void matchCursorPos(Tex &tex)
    // {
    //     if (!tex.console->setCursorPos({tex.currentContext.currentPositionIndex, tex.currentContext.currentLineIndex}))
    //     {
    //         std::cerr << "setCursorPos failed" << std::endl;
    //     }
    // }

    // void clearLine(Tex &tex)
    // {
    //     tex.console->setCursorPos({(*tex.currentContext.currentLine).size(), tex.currentContext.currentLineIndex});
    //     for(int i = tex.currentContext.currentPositionIndex; i < (int)(*tex.currentContext.currentLine).size(); i++) 
    //     {
    //         tex.console->clearCharAtCursor();
    //     }
    // }

    // void clearContent(Tex &tex) 
    // {
    //     tex.display.matchCursorPos(tex.currentContext);

    //     int lineCounter = 0;
    //     for(file_content::iterator it = tex.currentContext.currentLine; it != tex.currentContext.content.end(); it++) 
    //     {
    //         line::iterator lineStart;
    //         int lineStartIndex;
    //         if(it == tex.currentContext.currentLine)
    //         {
    //             lineStart = tex.currentContext.currentPosition;
    //             lineStartIndex = tex.currentContext.currentPositionIndex;
    //         }
    //         else
    //         {
    //             lineStart = (*it).begin();
    //             lineStartIndex = 0;
    //         }

    //         tex.display.console->setCursorPos({(*it).size(), tex.currentContext.currentLineIndex + lineCounter});
    //         for(int i = lineStartIndex; i < (int)(*it).size(); i++) 
    //         {
    //             tex.display.console->clearCharAtCursor();
    //         }

    //         lineCounter++;
    //     }

    //     tex.display.matchCursorPos(tex.currentContext);
    // }

    // void renderCurrentLine(Tex &tex) 
    // {
    //     line::iterator it = tex.currentContext.currentPosition; 
    //     for(int i = tex.currentContext.currentPositionIndex; i < (int)(*tex.currentContext.currentLine).size(); i++) 
    //     {
    //         tex.console->insertCharAtCursor(*it);
    //         it++;
    //     }
    //     matchCursorPos(tex);
    // }

    // void renderContent(Tex &tex) 
    // {
    //     tex.display.matchCursorPos(tex.currentContext);

    //     int lineCounter = 0;
    //     for(file_content::iterator it = tex.currentContext.currentLine; it != tex.currentContext.content.end(); it++) 
    //     {
    //         line::iterator lineStart;
    //         if(it == tex.currentContext.currentLine)
    //         {
    //             lineStart = tex.currentContext.currentPosition;
    //         }
    //         else
    //         {
    //             lineStart = (*it).begin();
    //         }

    //         for(line::iterator lineIt = lineStart; lineIt != (*it).end(); lineIt++) 
    //         {
    //             tex.display.console->insertCharAtCursor(*lineIt);
    //         }
    //         tex.display.console->insertCharAtCursor('\n');

    //         lineCounter++;
    //     }

    //     tex.display.matchCursorPos(tex.currentContext);
    // }

    void insertChar(Tex &tex)
    {
        tex.display.clearLine(tex.currentContext);

        tex.currentContext.insertChar(tex.lastPress.ch);

        tex.display.console->insertCharAtCursor(tex.lastPress.ch);

        tex.display.renderCurrentLine(tex.currentContext);
    }
    void enter(Tex &tex)
    {
        tex.display.clearContent(tex.currentContext);

        tex.currentContext.enter();

        tex.display.renderContent(tex.currentContext);
    }
    void backspace(Tex &tex)
    {
        pnt currentPos;
        tex.display.console->getCursorPos(currentPos);
        bool isContentChanged = currentPos.first == 0;

        isContentChanged ? tex.display.clearContent(tex.currentContext) : tex.display.clearLine(tex.currentContext);

        tex.currentContext.backspace();

        tex.display.console->clearCharAtCursor();

        isContentChanged ?  tex.display.renderContent(tex.currentContext) :  tex.display.renderCurrentLine(tex.currentContext);

    }
    void movePosRight(Tex &tex)
    {
        tex.currentContext.movePosRight();
        tex.display.matchCursorPos(tex.currentContext);
    }
    void movePosLeft(Tex &tex)
    {
        tex.currentContext.movePosLeft();
        tex.display.matchCursorPos(tex.currentContext);
    }
    void movePosUp(Tex &tex)
    {
        tex.currentContext.movePosUp();
        tex.display.matchCursorPos(tex.currentContext);
    }
    void movePosDown(Tex &tex)
    {
        tex.currentContext.movePosDown();
        tex.display.matchCursorPos(tex.currentContext);
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