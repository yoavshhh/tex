#pragma once

#include "console.hpp"
#include "../context/file_context.hpp"

namespace tex
{

class Display {
public:
    Console *console;

    Display();

    bool Init();

    void matchCursorPos(FileContext &context);

    void clearLine(FileContext &context);

    void clearContent(FileContext &context);

    void renderCurrentLine(FileContext &context);

    void renderContent(FileContext &context);
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 9b171d4 (made sure all display goes through display class)
    
    bool getCursorPos(pnt& pos);
    bool setCursorPos(const pnt& pos);
    void insertCharAtCursor(char ch);
    void clearCharAtCursor();
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> d36b1b7 (created display class to handle all the display)
=======
>>>>>>> 9b171d4 (made sure all display goes through display class)
=======
private:
    int headerLinePadding;
>>>>>>> ddca507 (added init to display class)
};

}