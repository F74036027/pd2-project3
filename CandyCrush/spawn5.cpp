#include "spawn5.h"
#include <QDebug>
#include "destroy.h"
#include "horizontal.h"
#include "vertical.h"
#include "nineblock.h"

Spawn5::Spawn5()
{

}

void Spawn5::spawn(Blank * b[10][10],Blank * clicked,int mode)
{
    int row=clicked->row;
    int col=clicked->column;
    int num=clicked->number;
    int FiveNum[5]={0};

    switch(mode){
    case 1:// vertical normal component
        clicked->number=5;
        if(col>=2&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))){
            b[row][col-2]->number=0;
            b[row][col-1]->number=0;
        }// left condition
        if(col<=7&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))){
            b[row][col+1]->number=0;
            b[row][col+2]->number=0;
        }// right condition

        if(b[row-2][col]->number/10!=0)FiveNum[0]=b[row-2][col]->number%10;
        if(b[row-1][col]->number/10!=0)FiveNum[1]=b[row-1][col]->number%10;
        FiveNum[2]=b[row][col]->number;
        if(b[row+1][col]->number/10!=0)FiveNum[3]=b[row+1][col]->number%10;
        if(b[row+2][col]->number/10!=0)FiveNum[4]=b[row+2][col]->number%10;

        for(int i=0;i<5;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row-2+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            }
        }
        break;
    case 2:// horizontal normal component
        clicked->number=5;
        if(row>=2&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
            b[row-2][col]->number=0;
            b[row-1][col]->number=0;
        }// up condition
        if(row<=7&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
            b[row-2][col]->number=0;
            b[row-1][col]->number=0;
        }// down condition

        if(b[row][col-2]->number/10!=0)FiveNum[0]=b[row][col-2]->number%10;
        if(b[row][col-1]->number/10!=0)FiveNum[1]=b[row][col-1]->number%10;
        FiveNum[2]=b[row][col]->number;
        if(b[row][col+1]->number/10!=0)FiveNum[3]=b[row][col+1]->number%10;
        if(b[row][col+2]->number/10!=0)FiveNum[4]=b[row][col+2]->number%10;

        for(int i=0;i<5;i++){
            Destroy * d;
            switch(FiveNum[i]){
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
    case 3:// vertical special component
        num/=10;
        if(col>=2&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))){
            b[row][col-2]->number=0;
            b[row][col-1]->number=0;
        }// left condition
        if(col<=7&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))){
            b[row][col+1]->number=0;
            b[row][col+2]->number=0;
        }// right condition

        if(b[row-2][col]->number/10!=0)FiveNum[0]=b[row-2][col]->number%10;
        if(b[row-1][col]->number/10!=0)FiveNum[1]=b[row-1][col]->number%10;
        FiveNum[2]=b[row][col]->number%10;
        if(b[row+1][col]->number/10!=0)FiveNum[3]=b[row+1][col]->number%10;
        if(b[row+2][col]->number/10!=0)FiveNum[4]=b[row+2][col]->number%10;

        for(int i=0;i<5;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row-2+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row-2+i][col]);
                delete d;
                break;
            }
        }

        break;
    case 4:// horizontal special component
        num/=10;
        if(row>=2&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
            b[row-2][col]->number=0;
            b[row-1][col]->number=0;
        }// up condition
        if(row<=7&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
            b[row-2][col]->number=0;
            b[row-1][col]->number=0;
        }// down condition

        if(b[row][col-2]->number/10!=0)FiveNum[0]=b[row][col-2]->number%10;
        if(b[row][col-1]->number/10!=0)FiveNum[1]=b[row][col-1]->number%10;
        FiveNum[2]=b[row][col]->number%10;
        if(b[row][col+1]->number/10!=0)FiveNum[3]=b[row][col+1]->number%10;
        if(b[row][col+2]->number/10!=0)FiveNum[4]=b[row][col+2]->number%10;

        for(int i=0;i<5;i++){
            Destroy * d;
            switch(FiveNum[i]){
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
        qDebug()<<"spawn 5 error";
    }
}

void Spawn5::eliminate(Blank *b[10][10],Blank * clicked)
{
    // garbage function
}

int Spawn5::condition(Blank *b[10][10], Blank *focus)
{
    int row=focus->row;
    int col=focus->column;
    int num=focus->number;
    if(num!=0&&num!=5){
        if(num/10==0){ // control normal component
            // vertical condition
            if(row>=2&&row<=7&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
                return 1;
            }

            // horizontal condition
            if(col>=2&&col<=7&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))){
                return 2;
            }
        }
        else if(num/10!=0){ // control special component
            num/=10;
            // vertical condition
            if(row>=2&&row<=7&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
                return 3;
            }

            // horizontal condition
            if(col>=2&&col<=7&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))){
                return 4;
            }
        }
    }
    return 0;
}


Spawn5::~Spawn5()
{

}

