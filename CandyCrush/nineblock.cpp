#include "nineblock.h"
#include <QDebug>
#include "destroy.h"
#include "horizontal.h"
#include "vertical.h"
#include "nineblock.h"

NineBlock::NineBlock()
{

}

void NineBlock::spawn(Blank * b[10][10],Blank * clicked,int mode,int *score)
{
    // garbage function
}

void NineBlock::eliminate(Blank *b[10][10], Blank *clicked,int *score)
{
    clicked->number=0;
    int row=clicked->row;
    int col=clicked->column;
    Destroy * d;
    int EightNum[8]={0};
    *score+=9;

    // find special component
    if(row-1>=0&&col-1>=0&&b[row-1][col-1]->number/10!=0){  EightNum[0]=b[row-1][col-1]->number%10;}
    if(row-1>=0&&b[row-1][col]->number/10!=0){              EightNum[1]=b[row-1][col]->number%10;}
    if(row-1>=0&&col+1<=9&&b[row-1][col+1]->number/10!=0){  EightNum[2]=b[row-1][col+1]->number%10;}
    if(col-1>=0&&b[row][col-1]->number/10!=0){              EightNum[3]=b[row][col-1]->number%10;}
    if(col+1<=9&&b[row][col+1]->number/10!=0){              EightNum[4]=b[row][col+1]->number%10;}
    if(row+1<=9&&col-1>=0&&b[row+1][col-1]->number/10!=0){  EightNum[5]=b[row+1][col-1]->number%10;}
    if(row+1<=9&&b[row+1][col]->number/10!=0){              EightNum[6]=b[row+1][col]->number%10;}
    if(row+1<=9&&col+1<=9&&b[row+1][col+1]->number/10!=0){  EightNum[7]=b[row+1][col+1]->number%10;}

    // reinitialize to zero (avoid infinite loop)
    if(row-1>=0&&col-1>=0){  b[row-1][col-1]->number=0;}
    if(row-1>=0){            b[row-1][col]->number=0;}
    if(row-1>=0&&col+1<=9){  b[row-1][col+1]->number=0;}
    if(col-1>=0){            b[row][col-1]->number=0;}
    if(col+1<=9){            b[row][col+1]->number=0;}
    if(row+1<=9&&col-1>=0){  b[row+1][col-1]->number=0;}
    if(row+1<=9){            b[row+1][col]->number=0;}
    if(row+1<=9&&col+1<=9){  b[row+1][col+1]->number=0;}

    if(row-1>=0&&col-1>=0){
        switch(EightNum[0]){
        case 0: // normal component
            b[row-1][col-1]->number=0;
        break;
        case 1: // vertical bomb
            d=new Vertical;
            d->eliminate(b,b[row-1][col-1],score);
            delete d;
            break;
        case 2: // horizontal bomb
            d=new Horizontal;
            d->eliminate(b,b[row-1][col-1],score);
            delete d;
            break;
        case 3: // bomb
            d=new NineBlock;
            d->eliminate(b,b[row-1][col-1],score);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }

    if(row-1>=0){
        switch(EightNum[1]){
        case 0: // normal component
            b[row-1][col]->number=0;
        break;
        case 1: // vertical bomb
            d=new Vertical;
            d->eliminate(b,b[row-1][col],score);
            delete d;
            break;
        case 2: // horizontal bomb
            d=new Horizontal;
            d->eliminate(b,b[row-1][col],score);
            delete d;
            break;
        case 3: // bomb
            d=new NineBlock;
            d->eliminate(b,b[row-1][col],score);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }

    if(row-1>=0&&col+1<=9){
        switch(EightNum[2]){
        case 0: // normal component
            b[row-1][col+1]->number=0;
        break;
        case 1: // vertical bomb
            d=new Vertical;
            d->eliminate(b,b[row-1][col+1],score);
            delete d;
            break;
        case 2: // horizontal bomb
            d=new Horizontal;
            d->eliminate(b,b[row-1][col+1],score);
            delete d;
            break;
        case 3: // bomb
            d=new NineBlock;
            d->eliminate(b,b[row-1][col+1],score);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }

    if(col-1>=0){
        switch(EightNum[3]){
        case 0: // normal component
            b[row][col-1]->number=0;
        break;
        case 1: // vertical bomb
            d=new Vertical;
            d->eliminate(b,b[row][col-1],score);
            delete d;
            break;
        case 2: // horizontal bomb
            d=new Horizontal;
            d->eliminate(b,b[row][col-1],score);
            delete d;
            break;
        case 3: // bomb
            d=new NineBlock;
            d->eliminate(b,b[row][col-1],score);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }

    if(col+1<=9){
        switch(EightNum[4]){
        case 0: // normal component
            b[row][col+1]->number=0;
        break;
        case 1: // vertical bomb
            d=new Vertical;
            d->eliminate(b,b[row][col+1],score);
            delete d;
            break;
        case 2: // horizontal bomb
            d=new Horizontal;
            d->eliminate(b,b[row][col+1],score);
            delete d;
            break;
        case 3: // bomb
            d=new NineBlock;
            d->eliminate(b,b[row][col+1],score);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }

    if(row+1<=9&&col-1>=0){
        switch(EightNum[5]){
        case 0: // normal component
            b[row+1][col-1]->number=0;
        break;
        case 1: // vertical bomb
            d=new Vertical;
            d->eliminate(b,b[row+1][col-1],score);
            delete d;
            break;
        case 2: // horizontal bomb
            d=new Horizontal;
            d->eliminate(b,b[row+1][col-1],score);
            delete d;
            break;
        case 3: // bomb
            d=new NineBlock;
            d->eliminate(b,b[row+1][col-1],score);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }

    if(row+1<=9){
        switch(EightNum[6]){
        case 0: // normal component
            b[row+1][col]->number=0;
        break;
        case 1: // vertical bomb
            d=new Vertical;
            d->eliminate(b,b[row+1][col],score);
            delete d;
            break;
        case 2: // horizontal bomb
            d=new Horizontal;
            d->eliminate(b,b[row+1][col],score);
            delete d;
            break;
        case 3: // bomb
            d=new NineBlock;
            d->eliminate(b,b[row+1][col],score);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }

    if(row+1<=9&&col+1<=9){
        switch(EightNum[7]){
        case 0: // normal component
            b[row+1][col+1]->number=0;
        break;
        case 1: // vertical bomb
            d=new Vertical;
            d->eliminate(b,b[row+1][col+1],score);
            delete d;
            break;
        case 2: // horizontal bomb
            d=new Horizontal;
            d->eliminate(b,b[row+1][col+1],score);
            delete d;
            break;
        case 3: // bomb
            d=new NineBlock;
            d->eliminate(b,b[row+1][col+1],score);
            delete d;
            break;
        default:
            qDebug()<<"Destroy nine block error";
        }
    }
}

int NineBlock::condition(Blank *b[10][10], Blank *focus)
{
    // garbage function
    return 0;
}

NineBlock::~NineBlock()
{

}

