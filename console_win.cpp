#ifdef _WIN32
#include "console_win.hpp"

namespace tex
{


bool Init(void)
{
    std::cout << Color::NONE;
    return true;
}


}

#endif