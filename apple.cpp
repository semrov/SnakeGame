#include "apple.h"
#include <QTime>
#include <QPainter>

Apple::Apple(int board_width,int board_height, int size):
    board_width(board_width),
    board_height(board_height)
{
    this->size = size;
    this->image.load(":/images/images/apple.png");
    generate_location();
}

void Apple::generate_location()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    this->x = qrand() % ((board_width-size) / size);
    this->y = qrand() % ((board_height-size) / size);
}

void Apple::draw(QPainter &qp)
{
    qp.drawImage(x,y,image);
}

int Apple::get_x()
{
    return x;
}

int Apple::get_y()
{
    return y;
}
