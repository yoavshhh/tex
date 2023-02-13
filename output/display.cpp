#include "dispaly.hpp"

namespace tex
{
    Display::Display() :
        console(Console::getConsole()),
        headerLinePadding(2) { }
        

    bool Display::Init()
    {
        if (!console->Init())
        {
            return false;
        }
        std::string header = "Tex - text editor";
        for(std::string::iterator ch = header.begin(); ch != header.end(); ch++)
        {
            console->insertCharAtCursor(*ch);
        }


        // console->setCursorPos({0, headerLinePadding + 2});
        // std::string ending = "ending test";
        // for(std::string::iterator ch = ending.begin(); ch != ending.end(); ch++)
        // {
            // console->insertCharAtCursor(*ch);
        // }
        console->setCursorPos({0, headerLinePadding});
        return true;
    }

    bool Display::getCursorPos(pnt& pos)
    {
        return console->getCursorPos(pos);
    }
    bool Display::setCursorPos(const pnt& pos)
    {
        return console->setCursorPos({pos.first, pos.second + headerLinePadding});
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
        {
            std::cerr << "setCursorPos failed" << std::endl;
        }
    }

    void Display::clearLine(FileContext &context)
    {
       setCursorPos({(*context.currentLine).size(), context.currentLineIndex});
        for(int i = context.currentPositionIndex; i < (int)(*context.currentLine).size(); i++) 
        {
           clearCharAtCursor();
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

           setCursorPos({(*it).size(), context.currentLineIndex + lineCounter});
            for(int i = lineStartIndex; i < (int)(*it).size(); i++) 
            {
               clearCharAtCursor();
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
           insertCharAtCursor(*it);
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
               insertCharAtCursor(*lineIt);
            }
           insertCharAtCursor('\n');

            lineCounter++;
        }

        matchCursorPos(context);
    }

}