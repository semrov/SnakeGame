
#ifndef APPLE_H
#define APPLE_H

#include <QImage>
#include<QPainter>
#include "drawable.h"
#include "position.h"
#include "snake.h"

class Snake;


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
    void generate_random_position(Snake &snake);
    Position get_position() const;
    virtual void draw(QPainter&);

};

#endif // APPLE_H
