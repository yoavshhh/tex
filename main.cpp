#include <iostream>

#include "tex.hpp"

int main(void)
{
    tex::Tex tex_app;
    if (!tex_app.Init())
    {
        std::cout << "Could not initialize" << std::endl;
        return 1;
    }
    tex_app.MainLoop();
    tex_app.Finish();
    return 0;
}

