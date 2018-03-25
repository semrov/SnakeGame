#include "apple.h"
#include <QTime>
#include <QPainter>

Apple::Apple(int board_width,int board_height, int dot_size):
    board_width(board_width),
    board_height(board_height),
    p(QPoint())
{
    this->size = dot_size;
    this->image.load(":/images/images/apple.png");
}

void Apple::generate_random_position(Snake &snake)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    int x,y;
    do
    {
        x = (qrand() % ((board_width-size) / size)) * size;
        y = qrand() % ((board_height-size) / size) * size;
    }
    while(snake.location_intersect_apple(x,y));

    this->p.rx() = x;
    this->p.ry() = y;
}

QPoint Apple::get_position() const
{
    return this->p;
}

void Apple::draw(QPainter &qp)
{
    qp.drawImage(p.x(),p.y(),image);
}

