#define GXX_EXPERIMENTAL_CXX0X
#include <unordered_map>
#include <functional>

#include "press.hpp"
#include "state.hpp"

class Tex {
public:
    std::unordered_map<Press, std::function<void(Tex*)>> inputToFunction;
    State currentState;

    Tex();

    bool Init();
    void MainLoop();
    void Finish();

    ~Tex();
};