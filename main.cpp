#include <iostream>

#include "tex/tex.hpp"

int main(void)
{
    tex::Tex tex_app;
    if (!tex_app.Init())
    {
        std::cout << "Could not initialize" << std::endl;
        return 1;
    }
    std::cout << std::make_pair(tex::Color::RED, tex::Color::BLACK) << "Initialized!" << tex::Color::NONE << std::endl;
    tex_app.MainLoop();
    tex_app.Finish();
    return 0;
}

