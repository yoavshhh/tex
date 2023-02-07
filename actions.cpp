#include "actions.hpp"

namespace tex
{

    void insertChar(Tex &tex) {
        tex.currentContext.insertChar(tex.lastPress.ch);
    }

    void enter(Tex &tex) {
        tex.currentContext.enter();
    }

}