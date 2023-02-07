#include <iostream>

#include "tex.hpp"

int main(void)
{
    std::cout << tex::Color::NONE;
    tex::Tex tex_app;
    if (!tex_app.Init())
    {
        std::cout << std::make_pair(tex::Color::RED, tex::Color::WHITE) << "Could not initialize" << std::endl;
        return 1;
    }
    std::cout << "Yo!" << std::make_pair(tex::Color::RED, tex::Color::BLACK) << "Initialized!" << tex::Color::GREEN << std::endl;
    tex_app.MainLoop();
    tex_app.Finish();
    return 0;
}

