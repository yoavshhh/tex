#include "dispaly.hpp"

namespace tex
{
    Display::Display() :
        console(Console::getConsole()) { }

<<<<<<< HEAD
    bool Display::getCursorPos(pnt& pos)
    {
        return console->getCursorPos(pos);
    }
    bool Display::setCursorPos(const pnt& pos)
    {
        return console->setCursorPos(pos);
    }
    void Display::insertCharAtCursor(char ch)
    {
        console->insertCharAtCursor(ch);
    }
    void Display::clearCharAtCursor()
    {
        console->clearCharAtCursor();
    }

    void Display::matchCursorPos(FileContext &context)
    {
        if (!setCursorPos({context.currentPositionIndex, context.currentLineIndex}))
=======
    void Display::matchCursorPos(FileContext &context)
    {
        if (!console->setCursorPos({context.currentPositionIndex, context.currentLineIndex}))
>>>>>>> d36b1b7 (created display class to handle all the display)
        {
            std::cerr << "setCursorPos failed" << std::endl;
        }
    }

    void Display::clearLine(FileContext &context)
    {
<<<<<<< HEAD
       setCursorPos({(*context.currentLine).size(), context.currentLineIndex});
        for(int i = context.currentPositionIndex; i < (int)(*context.currentLine).size(); i++) 
        {
           clearCharAtCursor();
=======
        console->setCursorPos({(*context.currentLine).size(), context.currentLineIndex});
        for(int i = context.currentPositionIndex; i < (int)(*context.currentLine).size(); i++) 
        {
            console->clearCharAtCursor();
>>>>>>> d36b1b7 (created display class to handle all the display)
        }
    }

    void Display::clearContent(FileContext& context)
    {
        matchCursorPos(context);

        int lineCounter = 0;
        for(file_content::iterator it = context.currentLine; it != context.content.end(); it++) 
        {
            line::iterator lineStart;
            int lineStartIndex;
            if(it == context.currentLine)
            {
                lineStart = context.currentPosition;
                lineStartIndex = context.currentPositionIndex;
            }
            else
            {
                lineStart = (*it).begin();
                lineStartIndex = 0;
            }

<<<<<<< HEAD
           setCursorPos({(*it).size(), context.currentLineIndex + lineCounter});
            for(int i = lineStartIndex; i < (int)(*it).size(); i++) 
            {
               clearCharAtCursor();
=======
            console->setCursorPos({(*it).size(), context.currentLineIndex + lineCounter});
            for(int i = lineStartIndex; i < (int)(*it).size(); i++) 
            {
                console->clearCharAtCursor();
>>>>>>> d36b1b7 (created display class to handle all the display)
            }

            lineCounter++;
        }

        matchCursorPos(context);
    }

    void Display::renderCurrentLine(FileContext &context)
    {
        line::iterator it = context.currentPosition; 
        for(int i = context.currentPositionIndex; i < (int)(*context.currentLine).size(); i++) 
        {
<<<<<<< HEAD
           insertCharAtCursor(*it);
=======
            console->insertCharAtCursor(*it);
>>>>>>> d36b1b7 (created display class to handle all the display)
            it++;
        }
        matchCursorPos(context);
    }

    void Display::renderContent(FileContext &context)
    {
        matchCursorPos(context);

        int lineCounter = 0;
        for(file_content::iterator it = context.currentLine; it != context.content.end(); it++) 
        {
            line::iterator lineStart;
            if(it == context.currentLine)
            {
                lineStart = context.currentPosition;
            }
            else
            {
                lineStart = (*it).begin();
            }

            for(line::iterator lineIt = lineStart; lineIt != (*it).end(); lineIt++) 
            {
<<<<<<< HEAD
               insertCharAtCursor(*lineIt);
            }
           insertCharAtCursor('\n');
=======
                console->insertCharAtCursor(*lineIt);
            }
            console->insertCharAtCursor('\n');
>>>>>>> d36b1b7 (created display class to handle all the display)

            lineCounter++;
        }

        matchCursorPos(context);
    }

}