#pragma once

#include <iostream>

namespace tex
{


enum class Color {
    BLACK,
    BLUE,
    GREEN,
    AQUA,
    RED,
    PURPLE,
    YELLOW,
    WHITE,
    GREY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_AQUA,
    LIGHT_RED,
    LIGHT_PURPLE,
    LIGHT_YELLOW,
    LIGHT_WHITE,
    NONE
};


}


std::ostream& operator<<(std::ostream& s, std::pair<tex::Color, tex::Color>&& colors);
std::ostream& operator<<(std::ostream& s, tex::Color&& col);