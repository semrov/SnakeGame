#include "snake.h"

Snake::Snake(int board_width, int board_height, int dot_size) :
    board_width(board_width),
    board_height(board_height),
    dot_size(dot_size),
    snake(QVector<Position>())
{
    this->head.load(":/images/images/head.png");
    this->body.load(":/images/images/dot.png");

    this->snake.reserve(256);

    for(int i=0; i < 3; i++)
    {
        this->snake.append(Position((board_width/2) + i*dot_size,board_height/2));
    }
}

void Snake::draw(QPainter &qp)
{
    qp.drawImage(snake[0].get_x(),snake[0].get_y(),head);
    for(int i = 1; i < snake.size(); i++)
    {
        qp.drawImage(snake[i].get_x(),snake[i].get_y(),body);
    }
}
