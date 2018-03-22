#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
};

#endif // WIDGET_H
