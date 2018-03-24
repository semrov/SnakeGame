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

bool Snake::move(Direction direction)
{
    if(check_collission()) return false;

    for(int i = snake.length() - 1; i > 0; i--)
    {
        snake[i] = snake[i-1];
    }

    switch(direction)
    {
        case Direction::Up:
            snake[0].set_x(snake[0].get_x() - dot_size);
            break;
        case Direction::Down:
            snake[0].set_x(snake[0].get_x() + dot_size);
            break;
        case Direction::Left:
            snake[0].set_y(snake[0].get_y() - dot_size);
            break;
        case Direction::Right:
            snake[0].set_y(snake[0].get_y() + dot_size);
            break;
    }

    return true;
}

bool Snake::check_apple(const Apple &apple)
{
    return apple.get_position() == snake[0];
}

bool Snake::check_collission()
{
    for(int i = snake.length(); i > 4; i--)
    {
        if(snake[0].get_x() == snake[i].get_x() && snake[0].get_y() == snake[i].get_y())
            return true;
    }

    if(snake[0].get_x() < 0 || snake[0].get_x() >= board_width)
        return true;

    return snake[0].get_y() < 0 || snake[0].get_y() >= board_height;
}

void Snake::draw(QPainter &qp)
{
    qp.drawImage(snake[0].get_x(),snake[0].get_y(),head);
    for(int i = 1; i < snake.size(); i++)
    {
        qp.drawImage(snake[i].get_x(),snake[i].get_y(),body);
    }
}
