#include "SnakeGame.h"
#include "ui_widget.h"

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

    qDebug() << "Apple's position: " << apple.get_position() ;
    qDebug() << "Snake's head position: " << snake.get_head_posotion() ;

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
            //qDebug() << "Left key was clicked!" ;
            break;
        case Qt::Key_Right:
            if(current_direction != Direction::Left)
                current_direction = Direction::Right;
            //qDebug() << "Right key was clicked!";
            break;
        case Qt::Key_Up:
            if(current_direction != Direction::Down)
                current_direction = Direction::Up;
            //qDebug() << "Up key was clicked!";
            break;
        case Qt::Key_Down:
            if(current_direction != Direction::Up)
                current_direction = Direction::Down;
            //qDebug() << "Down key was clicked!";
            break;
        default:
            break;
    }

}

void SnakeGame::gameOver(QPainter &qp)
{
    QString message = "Game over";
    QFont font("Currier",20,QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

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
