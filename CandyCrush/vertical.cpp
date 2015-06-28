#include "vertical.h"
#include <QDebug>
#include "destroy.h"
#include "horizontal.h"
#include "vertical.h"
#include "nineblock.h"

Vertical::Vertical()
{

}

void Vertical::spawn(Blank * b[10][10],Blank * clicked,int mode,int *score)
{
    // garbage function
}

void Vertical::eliminate(Blank *b[10][10], Blank *clicked,int *score)
{
    clicked->number=0;
    int col=clicked->column;
    Destroy * d;
    int TenNum[10]={0};
    *score+=10;

    for(int i=0;i<10;i++){
        if(b[i][col]->number/10!=0){
            TenNum[i]=b[i][col]->number%10;
        }
        b[i][col]->number=0; // reinitialize to zero (avoid infinite loop)
    }

    for(int i=0;i<10;i++){
        switch(TenNum[i]){
        case 0: // normal component
            b[i][col]->number=0;
        break;
        case 1: // vertical bomb
            d=new Vertical;
            d->eliminate(b,b[i][col],score);
            delete d;
            break;
        case 2: // horizontal bomb
            d=new Horizontal;
            d->eliminate(b,b[i][col],score);
            delete d;
            break;
        case 3: // bomb
            d=new NineBlock;
            d->eliminate(b,b[i][col],score);
            delete d;
            break;
        default:
            qDebug()<<"Destroy vertical line error";
        }
    }
}

int Vertical::condition(Blank *b[10][10], Blank *focus)
{
    // garbage function
    return 0;
}

Vertical::~Vertical()
{

}

