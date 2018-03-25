#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include "apple.h"
#include "snake.h"
#include "direction.h"

namespace Ui {
class Widget;
}

class SnakeGame : public QWidget
{
    Q_OBJECT

public:
    explicit SnakeGame(QWidget *parent = 0);
    ~SnakeGame();

private:
    Ui::Widget *ui;

    static const int BOARD_WIDHT = 600;
    static const int BOARD_HEIGHT = 600;
    static const int DOT_SIZE = 10;
    static const int ALL_DOTS = (BOARD_WIDHT*BOARD_HEIGHT)/(DOT_SIZE*DOT_SIZE);
    static const int DELAY = 140;

    Snake snake;
    Apple apple;
    Direction current_direction;
    int timerID;
    bool inGame;

    void doDrawing();
    void gameOver(QPainter &qp);

protected:
    virtual void timerEvent(QTimerEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;

};

#endif // WIDGET_H
