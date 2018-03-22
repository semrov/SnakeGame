#include <QImage>
#include<QPainter>
#include "drawable.h"

#ifndef APPLE_H
#define APPLE_H

class Apple : public Drawable
{

public:
    Apple(int board_width, int board_height, int size);     // creates a new apple in random postition between board_width and board_height


private:
    const int board_width,board_height;
    int x,y; // position on an apple on the board
    QImage image; //image of apple displayed on the board
    int size;

public:
    void generate_location();
    int get_x();
    int get_y();
    virtual void draw(QPainter&);

};

#endif // APPLE_H
