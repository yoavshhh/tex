#include "console.hpp"

#include "windows/console_win.hpp"

namespace tex
{

Console *Console::getConsole(void)
{
#if defined(_WIN32)
    return new ConsoleWin;
#else
    return NULL;
#endif
}


}