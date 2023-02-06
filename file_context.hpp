#include <string>
#include <list>

#include "state.hpp"

typedef std::list<char> line;
typedef std::list<line> file_content;


namespace tex
{

class FileContext {
public:
    std::string fileName;
    file_content content;
    line::iterator currentPosition;
    file_content::iterator currentLine;
    State state;

    FileContext(std::string fileName);
};

}
