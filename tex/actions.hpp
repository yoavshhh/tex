#pragma once
#include "tex.hpp"

namespace tex
{

void insertChar(class Tex &t);
void enter(class Tex &t);
void backspace(class Tex &t);
void movePosRight(class Tex &t);
void movePosLeft(class Tex &t);
void movePosUp(class Tex &t);
void movePosDown(class Tex &t);

}