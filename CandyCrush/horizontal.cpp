#include "horizontal.h"
#include <QDebug>
#include "destroy.h"
#include "horizontal.h"
#include "vertical.h"
#include "nineblock.h"

Horizontal::Horizontal()
{

}

void Horizontal::spawn(Blank * b[10][10],Blank * clicked,int mode)
{
    // garbage function
}

void Horizontal::eliminate(Blank *b[10][10], Blank *clicked)
{
    clicked->number=0;
    int row=clicked->row;
    Destroy * d;
    int TenNum[10]={0};

    for(int i=0;i<10;i++){
        if(b[row][i]->number/10!=0){
            TenNum[i]=b[row][i]->number%10;
        }
        b[row][i]->number=0; // reinitialize to zero (avoid infinite loop)
    }

    for(int i=0;i<10;i++){
        switch(TenNum[i]){
        case 0: // normal component
        break;
        case 1: // vertical bomb
            d=new Vertical;
            d->eliminate(b,b[row][i]);
            delete d;
            break;
        case 2: // horizontal bomb
            d=new Horizontal;
            d->eliminate(b,b[row][i]);
            delete d;
            break;
        case 3: // bomb
            d=new NineBlock;
            d->eliminate(b,b[row][i]);
            delete d;
            break;
        default:
            qDebug()<<"Destroy horizontal line error";
        }
    }
}

int Horizontal::condition(Blank *b[10][10], Blank *focus)
{
    // garbage function
    return 0;
}

Horizontal::~Horizontal()
{

}

