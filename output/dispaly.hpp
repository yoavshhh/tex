#pragma once

#include "console.hpp"
#include "../context/file_context.hpp"

namespace tex
{

class Display {
public:
    Console *console;

    Display();

    void matchCursorPos(FileContext &context);

    void clearLine(FileContext &context);

    void clearContent(FileContext &context);

    void renderCurrentLine(FileContext &context);

    void renderContent(FileContext &context);
};

}