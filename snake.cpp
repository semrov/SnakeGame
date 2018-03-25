#include "snake.h"

Snake::Snake(int board_width, int board_height, int dot_size) :
    board_width(board_width),
    board_height(board_height),
    dot_size(dot_size),
    snake(QVector<QPoint>())
{
    this->head.load(":/images/images/head.png");
    this->body.load(":/images/images/dot.png");

    this->snake.reserve(256);

    for(int i=0; i < 3; i++)
    {
        this->snake.append(QPoint((board_width/2) + i*dot_size,board_height/2));
    }
}

bool Snake::move(Direction direction)
{
    for(int i = snake.length() - 1; i > 0; i--)
    {
        snake[i] = snake[i-1];
    }

    switch(direction)
    {
        case Direction::Up:
            snake[0].ry() -= dot_size;
            break;
        case Direction::Down:
            snake[0].ry() += dot_size;
            break;
        case Direction::Left:
            snake[0].rx() -= dot_size;
            break;
        case Direction::Right:
            snake[0].rx() += dot_size;
            break;
    }

    if(check_collission()) return false;

    return true;
}

bool Snake::check_apple(const Apple &apple)
{
    if (apple.get_position() == snake[0])
    {
        snake.append(QPoint());
        return true;
    }
    return false;
}

bool Snake::location_intersect_apple(int x, int y)
{
    for(int i=0; i<snake.length(); i++)
    {
        if (snake[i].x() == x && snake[i].y() == y)
            return true;
    }
    return false;
}

bool Snake::check_collission()
{

    for(int i = snake.length() - 1; i > 4; i--)
    {
        if(snake[0].x() == snake[i].x() && snake[0].y() == snake[i].y())
            return true;
    }


    if(snake[0].x() < 0 || snake[0].x() >= board_width)
        return true;

    return snake[0].y() < 0 || snake[0].y() >= board_height;
}

QPoint Snake::get_head_posotion()
{
    return snake[0];
}

void Snake::draw(QPainter &qp)
{
    qp.drawImage(snake[0].x(),snake[0].y(),head);
    for(int i = 1; i < snake.size(); i++)
    {
        qp.drawImage(snake[i].x(),snake[i].y(),body);
    }
}
