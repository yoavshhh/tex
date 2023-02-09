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

    void clearContent(Tex &tex) 
    {
        matchCursorPos(tex);

        int lineCounter = 0;
        for(file_content::iterator it = tex.currentContext.currentLine; it != tex.currentContext.content.end(); it++) 
        {
            line::iterator lineStart;
            int lineStartIndex;
            if(it == tex.currentContext.currentLine)
            {
                lineStart = tex.currentContext.currentPosition;
                lineStartIndex = tex.currentContext.currentPositionIndex;
            }
            else
            {
                lineStart = (*it).begin();
                lineStartIndex = 0;
            }

            tex.console->setCursorPos({(*it).size(), tex.currentContext.currentLineIndex + lineCounter});
            for(int i = lineStartIndex; i < (int)(*it).size(); i++) 
            {
                tex.console->clearCharAtCursor();
            }

            lineCounter++;
        }

        matchCursorPos(tex);
    }

    void renderCurrentLine(Tex &tex) 
    {
        line::iterator it = tex.currentContext.currentPosition; 
        for(int i = tex.currentContext.currentPositionIndex; i < (int)(*tex.currentContext.currentLine).size(); i++) 
        {
            tex.console->insertCharAtCursor(*it);
            it++;
        }
        matchCursorPos(tex);
    }

    void renderContent(Tex &tex) 
    {
        matchCursorPos(tex);

        int lineCounter = 0;
        for(file_content::iterator it = tex.currentContext.currentLine; it != tex.currentContext.content.end(); it++) 
        {
            line::iterator lineStart;
            if(it == tex.currentContext.currentLine)
            {
                lineStart = tex.currentContext.currentPosition;
            }
            else
            {
                lineStart = (*it).begin();
            }

            for(line::iterator lineIt = lineStart; lineIt != (*it).end(); lineIt++) 
            {
                tex.console->insertCharAtCursor(*lineIt);
            }
            tex.console->insertCharAtCursor('\n');

            lineCounter++;
        }

        matchCursorPos(tex);
    }

    void insertChar(Tex &tex)
    {
        clearLine(tex);

        tex.currentContext.insertChar(tex.lastPress.ch);

        tex.console->insertCharAtCursor(tex.lastPress.ch);

        renderCurrentLine(tex);
    }
    void enter(Tex &tex)
    {
        clearContent(tex);

        tex.currentContext.enter();

        renderContent(tex);
    }
    void backspace(Tex &tex)
    {
        pnt currentPos;
        tex.console->getCursorPos(currentPos);
        bool isContentChanged = currentPos.first == 0;

        isContentChanged ? clearContent(tex) : clearLine(tex);

        tex.currentContext.backspace();

        tex.console->clearCharAtCursor();

        isContentChanged ? renderContent(tex) : renderCurrentLine(tex);

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