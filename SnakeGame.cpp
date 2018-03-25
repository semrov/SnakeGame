#include "SnakeGame.h"
#include "ui_widget.h"
#include <QPen>

SnakeGame::SnakeGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    snake(Snake(BOARD_WIDHT,BOARD_HEIGHT,DOT_SIZE)),
    apple(Apple(BOARD_WIDHT,BOARD_HEIGHT,DOT_SIZE)),
    current_direction(Direction::Left)
{
    //ui->setupUi(this);
    setStyleSheet("background-color:black");
    resize(BOARD_WIDHT,BOARD_HEIGHT);
    apple.generate_random_position(snake);
    timerID = startTimer(DELAY);
    inGame = true;
}

void SnakeGame::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    if(inGame)
    {
        if(snake.check_apple(apple))
            apple.generate_random_position(snake);
        inGame = snake.move(current_direction);
        if(!inGame)
        {
            killTimer(timerID);
        }
    }
    repaint();
}

void SnakeGame::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    doDrawing();
}

void SnakeGame::doDrawing()
{
    QPainter qp(this);

    if(inGame)
    {
        apple.draw(qp);
        snake.draw(qp);
    }
    else
    {
        gameOver(qp);
    }
}

void SnakeGame::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Left:
            if(current_direction != Direction::Right)
                current_direction = Direction::Left;
            break;
        case Qt::Key_Right:
            if(current_direction != Direction::Left)
                current_direction = Direction::Right;
            break;
        case Qt::Key_Up:
            if(current_direction != Direction::Down)
                current_direction = Direction::Up;
            break;
        case Qt::Key_Down:
            if(current_direction != Direction::Up)
                current_direction = Direction::Down;
            break;
        default:
            break;
    }

}

void SnakeGame::gameOver(QPainter &qp)
{
    QString message = "Game over";
    QFont font("Courier",20,QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

    QPen penText(QColor("#FF0000"));
    qp.setPen(penText);

    qp.setFont(font);
    int h = height();
    int w = width();

    qp.translate(QPoint(w/2,h/2));
    qp.drawText(-textWidth/2,0,message);
}

SnakeGame::~SnakeGame()
{
    //delete ui;
}
