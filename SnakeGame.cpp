#include "SnakeGame.h"
#include "ui_widget.h"

SnakeGame::SnakeGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

SnakeGame::~SnakeGame()
{
    delete ui;
}
