#include "file_context.hpp"

namespace tex
{

FileContext::FileContext(std::string fileName) : fileName(fileName),
                                                 content({{}}),
                                                 currentLine(content.begin()),
                                                 currentPosition((*content.begin()).begin()),
                                                 state(State::INSERT) { }

void FileContext::insertChar(char ch) {
    (*currentLine).emplace(currentPosition, ch);
}

}