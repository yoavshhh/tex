#include "actions.hpp"

namespace tex
{

    void insertChar(Tex* tex) {
        tex->currentContext.insertChar(tex->lastPress.ch);
    }

}