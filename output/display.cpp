#include "dispaly.hpp"

namespace tex
{
    Display::Display() :
        console(Console::getConsole()) { }

    void Display::matchCursorPos(FileContext &context)
    {
        if (!console->setCursorPos({context.currentPositionIndex, context.currentLineIndex}))
        {
            std::cerr << "setCursorPos failed" << std::endl;
        }
    }

    void Display::clearLine(FileContext &context)
    {
        console->setCursorPos({(*context.currentLine).size(), context.currentLineIndex});
        for(int i = context.currentPositionIndex; i < (int)(*context.currentLine).size(); i++) 
        {
            console->clearCharAtCursor();
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

            console->setCursorPos({(*it).size(), context.currentLineIndex + lineCounter});
            for(int i = lineStartIndex; i < (int)(*it).size(); i++) 
            {
                console->clearCharAtCursor();
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
            console->insertCharAtCursor(*it);
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
                console->insertCharAtCursor(*lineIt);
            }
            console->insertCharAtCursor('\n');

            lineCounter++;
        }

        matchCursorPos(context);
    }

}