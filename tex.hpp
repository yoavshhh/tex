#define GXX_EXPERIMENTAL_CXX0X
#include <unordered_map>
#include <functional>

#include "press.hpp"
#include "state.hpp"
#include "file_context.hpp"

namespace tex 
{

class Tex {
private:
    FileContext currentContext;
public:
    std::unordered_map<Press, std::function<void(Tex*)>> inputMap;

    Tex();
    Tex(std::string fileName);

    bool Init();
    void MainLoop();
    void Finish();

    ~Tex();
};

}
