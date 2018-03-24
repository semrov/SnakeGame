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

void Position::set_x(int x)
{
    this->x = x;
}

void Position::set_y(int y)
{
    this->y = y;
}
bool Position::operator==(const Position &other)
{
    return this->x == other.x && this->y == other.y;
}
