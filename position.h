#ifndef POSITION_H
#define POSITION_H


class Position
{
    int x,y;
public:
    Position(int x, int y);
    Position();
    int get_x();
    int get_y();
    void set_x(int x);
    void set_y(int y);
    virtual bool operator==(const Position &other);
};

#endif // POSITION_H
