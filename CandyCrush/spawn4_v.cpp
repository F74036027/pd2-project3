#include "spawn4_v.h"
#include <QDebug>
#include "destroy.h"
#include "vertical.h"
#include "horizontal.h"
#include "nineblock.h"

Spawn4_V::Spawn4_V()
{

}

void Spawn4_V::spawn(Blank * b[10][10],Blank * clicked,int mode)
{
    int row=clicked->row;
    int col=clicked->column;
    int num=clicked->number;
    int FourNum[4]={0};
    Destroy * d;

    switch(mode){
    case 1: // O normal component
            // X
            // O
            // O

        clicked->number=clicked->number*10+1;

        if(b[row-1][col]->number/10!=0)FourNum[0]=b[row-1][col]->number%10;
        FourNum[1]=b[row][col]->number;
        if(b[row+1][col]->number/10!=0)FourNum[2]=b[row+1][col]->number%10;
        if(b[row+2][col]->number/10!=0)FourNum[3]=b[row+2][col]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                b[row-1+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row-1+i][col]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row-1+i][col]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row-1+i][col]);
                delete d;
                break;
            }
        }

        break;
    case 2: // O normal component
            // O
            // X
            // O

        clicked->number=clicked->number*10+1;

        if(b[row-2][col]->number/10!=0)FourNum[0]=b[row-2][col]->number%10;
        if(b[row-1][col]->number/10!=0)FourNum[1]=b[row-1][col]->number%10;
        FourNum[2]=b[row][col]->number;
        if(b[row+1][col]->number/10!=0)FourNum[3]=b[row+1][col]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
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
    case 3: // O special component
            // X
            // O
            // O

        if(b[row-1][col]->number/10!=0)FourNum[0]=b[row-1][col]->number%10;
        FourNum[1]=b[row][col]->number%10;
        if(b[row+1][col]->number/10!=0)FourNum[2]=b[row+1][col]->number%10;
        if(b[row+2][col]->number/10!=0)FourNum[3]=b[row+2][col]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                b[row-1+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row-1+i][col]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row-1+i][col]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row-1+i][col]);
                delete d;
                break;
            }
        }

        break;
    case 4: // O special component
            // O
            // X
            // O

        if(b[row-2][col]->number/10!=0)FourNum[0]=b[row-2][col]->number%10;
        if(b[row-1][col]->number/10!=0)FourNum[1]=b[row-1][col]->number%10;
        FourNum[2]=b[row][col]->number%10;
        if(b[row+1][col]->number/10!=0)FourNum[3]=b[row+1][col]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
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
    default:
        qDebug()<<"Spawn horizontal bomb error";
    }
}

void Spawn4_V::eliminate(Blank *b[10][10],Blank * clicked)
{
    // garbage function
}

int Spawn4_V::condition(Blank *b[10][10], Blank *focus)
{
    int row=focus->row;
    int col=focus->column;
    int num=focus->number;
    if(num!=0&&num!=5){
        if(num/10==0){ // control normal component
            // O
            // X
            // O
            // O condition
            if(row>=1&&row<=7&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
                return 1;
            }

            // O
            // O
            // X
            // O condition
            if(row>=2&&row<=8&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
                return 2;
            }
        }
        else if(num/10!=0){ // control special component
            num/=10;
            // O
            // X
            // O
            // O condition
            if(row>=1&&row<=7&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
                return 3;
            }

            // O
            // O
            // X
            // O condition
            if(row>=2&&row<=8&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
                return 4;
            }
        }
    }
    return 0;
}

Spawn4_V::~Spawn4_V()
{

}

