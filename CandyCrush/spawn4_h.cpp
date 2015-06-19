#include "spawn4_h.h"
#include <QDebug>
#include "destroy.h"
#include "vertical.h"
#include "horizontal.h"
#include "nineblock.h"

Spawn4_H::Spawn4_H()
{

}

void Spawn4_H::spawn(Blank * b[10][10],Blank * clicked,int mode)
{
    int row=clicked->row;
    int col=clicked->column;
    int FourNum[4]={0};
    Destroy * d;

    switch(mode){
    case 1:// OXOO normal component
        clicked->number=clicked->number*10+2;

        if(b[row][col-1]->number/10!=0)FourNum[0]=b[row][col-1]->number%10;
        FourNum[1]=b[row][col]->number;
        if(b[row][col+1]->number/10!=0)FourNum[2]=b[row][col+1]->number%10;
        if(b[row][col+2]->number/10!=0)FourNum[3]=b[row][col+2]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                b[row][col-1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-1+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-1+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-1+i]);
                delete d;
                break;
            }
        }

        break;
    case 2:// OOXO normal component
        clicked->number=clicked->number*10+2;

        if(b[row][col-2]->number/10!=0)FourNum[0]=b[row][col-2]->number%10;
        if(b[row][col-1]->number/10!=0)FourNum[1]=b[row][col-1]->number%10;
        FourNum[2]=b[row][col]->number;
        if(b[row][col+1]->number/10!=0)FourNum[3]=b[row][col+1]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                b[row][col-2+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            }
        }

        break;
    case 3:// OXOO special component

        if(b[row][col-1]->number/10!=0)FourNum[0]=b[row][col-1]->number%10;
        FourNum[1]=b[row][col]->number%10;
        if(b[row][col+1]->number/10!=0)FourNum[2]=b[row][col+1]->number%10;
        if(b[row][col+2]->number/10!=0)FourNum[3]=b[row][col+2]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                b[row][col-1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-1+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-1+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-1+i]);
                delete d;
                break;
            }
        }

        break;
    case 4:// OOXO special component

        if(b[row][col-2]->number/10!=0)FourNum[0]=b[row][col-2]->number%10;
        if(b[row][col-1]->number/10!=0)FourNum[1]=b[row][col-1]->number%10;
        FourNum[2]=b[row][col]->number%10;
        if(b[row][col+1]->number/10!=0)FourNum[3]=b[row][col+1]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                b[row][col-2+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-2+i]);
                delete d;
                break;
            }
        }

        break;
    default:
        qDebug()<<"Spawn horizontal bomb error";
    }
}

void Spawn4_H::eliminate(Blank *b[10][10],Blank * clicked)
{
    // garbage function
}

int Spawn4_H::condition(Blank *b[10][10], Blank *focus)
{
    int row=focus->row;
    int col=focus->column;
    int num=focus->number;
    if(num!=0&&num!=5){
        if(num/10==0){ // control normal component
            // OXOO condition
            if(col>=1&&col<=7&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))){
            return 1;
            }

            // OOXO condition
            if(col>=2&&col<=8&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))){
                return 2;
            }
        }
        else if(num/10!=0){ // control special component
            num/=10;
            // OXOO condition
            if(col>=1&&col<=7&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))){
            return 3;
            }

            // OOXO condition
            if(col>=2&&col<=8&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))){
                return 4;
            }
        }
    }
    return 0;
}

Spawn4_H::~Spawn4_H()
{

}

