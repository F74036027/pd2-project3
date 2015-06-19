#include "blank.h"
#include <QDebug>
#include <QTimer>

Blank::Blank(QWidget *parent, int Row, int Col) : QObject(parent),
    row(Row),column(Col),shift(1)
{
    button=new QPushButton(parent);
    time=new QTimer();
    //button->setFlat(true);
    //clicked=false;
    connect(button,SIGNAL(clicked()),this,SLOT(click()));
    button->setGeometry(column*50,row*50,50,50);
    //button->setIconSize(button->size());
}

Blank::~Blank()
{
    delete button;
}

void Blank::setRandonNumber()
{
    // 1 ~ 4 , not zero
    number=rand()%4+1;
    return;
}

void Blank::setButtonPicture()
{
    // 1 red, 2 yellow, 3 green, 4 blue
    switch(number){
        case 1:
            button->setIcon(QIcon(QPixmap(":/pic/red.png")));
            break;
        case 11:
            button->setIcon(QIcon(QPixmap(":/pic/red_vertical_bomb.png")));
            break;
        case 12:
            button->setIcon(QIcon(QPixmap(":/pic/red_horizontal_bomb.png")));
            break;
        case 13:
            button->setIcon(QIcon(QPixmap(":/pic/red_bomb.png")));
            break;
        case 2:
            button->setIcon(QIcon(QPixmap(":/pic/yellow.png")));
            break;
        case 21:
            button->setIcon(QIcon(QPixmap(":/pic/yellow_vertical_bomb.png")));
            break;
        case 22:
            button->setIcon(QIcon(QPixmap(":/pic/yellow_horizontal_bomb.png")));
            break;
        case 23:
            button->setIcon(QIcon(QPixmap(":/pic/yellow_bomb.png")));
            break;
        case 3:
            button->setIcon(QIcon(QPixmap(":/pic/green.png")));
            break;
        case 31:
            button->setIcon(QIcon(QPixmap(":/pic/green_vertical_bomb.png")));
            break;
        case 32:
            button->setIcon(QIcon(QPixmap(":/pic/green_horizontal_bomb.png")));
            break;
        case 33:
            button->setIcon(QIcon(QPixmap(":/pic/green_bomb.png")));
            break;
        case 4:
            button->setIcon(QIcon(QPixmap(":/pic/blue.png")));
            break;
        case 41:
            button->setIcon(QIcon(QPixmap(":/pic/blue_vertical_bomb.png")));
            break;
        case 42:
            button->setIcon(QIcon(QPixmap(":/pic/blue_horizontal_bomb.png")));
            break;
        case 43:
            button->setIcon(QIcon(QPixmap(":/pic/blue_bomb.png")));
            break;
        case 5:
            button->setIcon(QIcon(QPixmap(":/pic/power_bomb.png")));
            break;
        default:
            button->setIcon(QIcon(QPixmap("NO PICTURE")));
    }
    return;
}

void Blank::operator-(Blank *b)
{
    int tmp_number=number;
    number=b->number;
    b->number=tmp_number;
    connect(time,SIGNAL(timeout()),this,SLOT(moveright()));
    connect(b->time,SIGNAL(timeout()),b,SLOT(moveleft()));
    time->start(100);
    b->time->start(100);
}

void Blank::operator |(Blank *b)
{
    int tmp_number=number;
    number=b->number;
    b->number=tmp_number;
    connect(time,SIGNAL(timeout()),this,SLOT(movedown()));
    connect(b->time,SIGNAL(timeout()),b,SLOT(moveup()));
    time->start(100);
    b->time->start(100);
    return;
}

void Blank::click()
{
    emit Click(row,column);
}

void Blank::moveright()
{
    button->setGeometry(column*50+shift*10,row*50,50,50);
    shift++;
    if(shift>5){
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveright()));
        button->setGeometry(column*50,row*50,50,50);
        setButtonPicture();
        //time->stop();
        emit MoveDone();
    }
    return;
}

void Blank::moveleft()
{
    button->setGeometry(column*50-shift*10,row*50,50,50);
    shift++;
    if(shift>5){
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveleft()));
        button->setGeometry(column*50,row*50,50,50);
        setButtonPicture();
        //time->stop();
        //emit MoveDone();
    }
    return;
}

void Blank::movedown()
{
    button->setGeometry(column*50,row*50+shift*10,50,50);
    shift++;
    if(shift>5){
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(movedown()));
        button->setGeometry(column*50,row*50,50,50);
        setButtonPicture();
        //time->stop();
        emit MoveDone();
    }
    return;
}

void Blank::moveup()
{
    button->setGeometry(column*50,row*50-shift*10,50,50);
    shift++;
    if(shift>5){
        shift=1;
        disconnect(time,SIGNAL(timeout()),this,SLOT(moveup()));
        button->setGeometry(column*50,row*50,50,50);
        setButtonPicture();
        //time->stop();
        //emit MoveDone();
    }
    return;
}
