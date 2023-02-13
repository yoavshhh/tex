#include "actions.hpp"

namespace tex
{

    // void matchCursorPos(Tex &tex)
    // {
    //     if (!tex.setCursorPos({tex.currentContext.currentPositionIndex, tex.currentContext.currentLineIndex}))
    //     {
    //         std::cerr << "setCursorPos failed" << std::endl;
    //     }
    // }

    // void clearLine(Tex &tex)
    // {
    //     tex.setCursorPos({(*tex.currentContext.currentLine).size(), tex.currentContext.currentLineIndex});
    //     for(int i = tex.currentContext.currentPositionIndex; i < (int)(*tex.currentContext.currentLine).size(); i++) 
    //     {
    //         tex.clearCharAtCursor();
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

    //         tex.display.setCursorPos({(*it).size(), tex.currentContext.currentLineIndex + lineCounter});
    //         for(int i = lineStartIndex; i < (int)(*it).size(); i++) 
    //         {
    //             tex.display.clearCharAtCursor();
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
    //         tex.insertCharAtCursor(*it);
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
    //             tex.display.insertCharAtCursor(*lineIt);
    //         }
    //         tex.display.insertCharAtCursor('\n');

    //         lineCounter++;
    //     }

    //     tex.display.matchCursorPos(tex.currentContext);
    // }

    void insertChar(Tex &tex)
    {
        tex.display.clearLine(tex.currentContext);

        tex.currentContext.insertChar(tex.lastPress.ch);

        tex.display.insertCharAtCursor(tex.lastPress.ch);

        tex.display.renderCurrentLine(tex.currentContext);
    }
    void enter(Tex &tex)
    {
        tex.display.clearContent(tex.currentContext);

        tex.currentContext.enter();

        tex.display.renderContent(tex.currentContext);
    }
    void tab(Tex &tex)
    {
        int i;
        tex.display.clearLine(tex.currentContext);

        for(i = 0; i < TAB_SPACE_AMOUNT; i++)
        {
            tex.currentContext.insertChar(' ');
            tex.display.insertCharAtCursor(' ');
        }

        tex.display.renderCurrentLine(tex.currentContext);
    }
    void backspace(Tex &tex)
    {
        pnt currentPos;
        tex.display.getCursorPos(currentPos);
        bool isContentChanged = currentPos.first == 0;

        isContentChanged ? tex.display.clearContent(tex.currentContext) : tex.display.clearLine(tex.currentContext);

        tex.currentContext.backspace();

        tex.display.clearCharAtCursor();

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

}