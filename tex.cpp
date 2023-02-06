#include "tex.hpp"

namespace tex
{

Tex::Tex() : inputMap({}), currentContext(FileContext("")) { }
Tex::Tex(std::string fileName) : inputMap({}), currentContext(FileContext(fileName)) { }

}
