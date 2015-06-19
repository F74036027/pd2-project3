#include "all.h"
#include <QDebug>
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

All::All()
{

}

void All::spawn(Blank * b[10][10],Blank * clicked,int mode)
{
    // garbage function
}

void All::eliminate(Blank *b[10][10],Blank * clicked)
{
    // clicked is garbage value
    for(int i=0;i<10;i++){qDebug()<<"in";
        for(int j=0;j<10;j++){
           b[i][j]->number=0;
        }
    }
}

int All::condition(Blank *b[10][10], Blank *focus)
{
    // garbage function
}

All::~All()
{

}

