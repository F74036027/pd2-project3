#include "gameover.h"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent,int scoreNum,int starNum) :
    QMainWindow(parent),
    ui(new Ui::GameOver),score(scoreNum),star(starNum)
{
    ui->setupUi(this);
    scoreStr=QString::number(score,10);
    ui->scorePic->setText(scoreStr);
    if(star==0)ui->starPic->setText("No Star");
    if(star==1)ui->starPic->setPixmap(QPixmap(":/pic/star1.png"));
    if(star==2)ui->starPic->setPixmap(QPixmap(":/pic/star1.png"));
    if(star==3)ui->starPic->setPixmap(QPixmap(":/pic/star1.png"));
}

GameOver::~GameOver()
{
    delete ui;
    emit quit(star,score);
}
