#include <iostream>

#include "tex/tex.hpp"

int main(void)
{
    std::cout << tex::Color::NONE;
    tex::Tex tex_app;
    if (!tex_app.Init())
    {
        std::cout << std::make_pair(tex::Color::RED, tex::Color::WHITE) << "Could not initialize" << std::endl;
        return 1;
    }
    std::cout << tex::Color::RED << "Initialized!" << tex::Color::NONE << std::endl;
    tex_app.MainLoop();
    tex_app.Finish();
    return 0;
}

