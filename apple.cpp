#include "apple.h"
#include <QTime>
#include <QPainter>

Apple::Apple(int board_width,int board_height, int dot_size):
    board_width(board_width),
    board_height(board_height)
{
    this->size = dot_size;
    this->image.load(":/images/images/apple.png");
    generate_random_position();
}

void Apple::generate_random_position()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    int x = qrand() % ((board_width-size) / size);
    int y = qrand() % ((board_height-size) / size);

    this->p = Position(x,y);
}

Position Apple::get_position() const
{
    return this->p;
}

void Apple::draw(QPainter &qp)
{
    qp.drawImage(p.get_x(),p.get_y(),image);
}

