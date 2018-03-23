#include "position.h"

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

Position::Position()
{
    x = 0;
    y = 0;
}

int Position::get_x()
{
    return x;
}

int Position::get_y()
{
    return y;
}
