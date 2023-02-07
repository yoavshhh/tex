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
<<<<<<< HEAD
    std::cout << "Yo!" << std::make_pair(tex::Color::RED, tex::Color::BLACK) << "Initialized!" << tex::Color::GREEN << std::endl;
=======
    std::cout << std::make_pair(tex::Color::RED, tex::Color::BLACK) << "Initialized!" << tex::Color::NONE << std::endl;
>>>>>>> 836be1c1d5a91d8ae938d3d3619b7b0298a7164f
    tex_app.MainLoop();
    tex_app.Finish();
    return 0;
}

