#include <console.hpp>
    
#include "console.hpp"
#include "console_win.hpp"

namespace tex
{

static Console *getConsole(void)
{
#if defined(_WIN32)
    return new ConsoleWin();
#else
    return NULL;
#endif
}


}