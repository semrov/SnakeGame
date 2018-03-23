#include <QImage>
#include<QPainter>
#include "drawable.h"
#include "position.h"

#ifndef APPLE_H
#define APPLE_H

class Apple : public Drawable
{

public:
    Apple(int board_width, int board_height, int dot_size);     // creates a new apple in random postition between board_width and board_height


private:
    const int board_width,board_height;
    Position p; // position on an apple on the board
    QImage image; //image of apple displayed on the board
    int size;

public:
    void generate_random_position();
    Position get_position();
    virtual void draw(QPainter&);

};

#endif // APPLE_H
