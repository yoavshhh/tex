#include "user_input.hpp"

int main(void)
{
    Press::Init();
    Press p;
    while(p.ch != 'A')
    {
        p = Press::getPress();
        p.print();
    }
    return 0;
}