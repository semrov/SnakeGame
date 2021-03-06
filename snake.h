#ifndef SNAKE_H
#define SNAKE_H
#include "drawable.h"
#include "direction.h"
#include "apple.h"
#include <QImage>
#include <QPoint>

class Apple;

class Snake : public Drawable
{
private:
    const int board_width,board_height;
    const  int dot_size;

    // list of snake's position
    // snake[0] is the snake's head
    // snake[1..] is the snake's tail
    QVector<QPoint> snake;
    QImage head;
    QImage body;
public:
    Snake(int board_width, int board_height, int dot_size);
    bool move(Direction direction);
    bool check_apple(const Apple &apple);
    bool location_intersect_apple(int x, int y);
    QPoint get_head_posotion();
    virtual void draw(QPainter &qp);
private:
    bool check_collission();
};

#endif // SNAKE_H
