#include "user_input.hpp"

namespace tex 
{
    
    bool Press::operator ==(const Press& other) const {
        return (this->ch == other.ch) &&
            (this->state == other.state);
    }

}

namespace std
{
size_t hash<tex::Press>::operator()(const tex::Press& press) const {
        return ((size_t)press.ch << (sizeof(char)*8)) |
            ((size_t)press.state);
}
}