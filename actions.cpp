#include "actions.hpp"

namespace tex
{

    void insertChar(Tex* tex) {
        tex->currentContext.insertChar(tex->lastPress.ch);
    }

    void Enter(Tex* tex) {
        tex->currentContext.Enter();
    }

}