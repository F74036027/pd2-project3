#include "three_h.h"
#include <QDebug>
#include "destroy.h"
#include "horizontal.h"
#include "vertical.h"
#include "nineblock.h"

Three_H::Three_H()
{

}

void Three_H::spawn(Blank * b[10][10],Blank * clicked,int mode)
{
    int row=clicked->row;
    int col=clicked->column;
    Destroy * d;
    int ThreeNum[3]={0};

    switch(mode){
    case 1: // leftest normal component
        clicked->number=0;

        ThreeNum[0]=b[row][col]->number;
        if(b[row][col+1]->number/10!=0)ThreeNum[1]=b[row][col+1]->number%10;
        if(b[row][col+2]->number/10!=0)ThreeNum[2]=b[row][col+2]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                b[row][col+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col+i]);
                delete d;
                break;
            }
        }

        break;
    case 2: // middle normal component
        clicked->number=0;

        if(b[row][col-1]->number/10!=0)ThreeNum[0]=b[row][col-1]->number%10;
        ThreeNum[1]=b[row][col]->number;
        if(b[row][col+1]->number/10!=0)ThreeNum[2]=b[row][col+1]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    case 3: // rightest normal component
        clicked->number=0;

        if(b[row][col-2]->number/10!=0)ThreeNum[0]=b[row][col-2]->number%10;
        if(b[row][col-1]->number/10!=0)ThreeNum[1]=b[row][col-1]->number%10;
        ThreeNum[2]=b[row][col]->number;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    case 4: // leftest normal component

        ThreeNum[0]=b[row][col]->number%10;
        if(b[row][col+1]->number/10!=0)ThreeNum[1]=b[row][col+1]->number%10;
        if(b[row][col+2]->number/10!=0)ThreeNum[2]=b[row][col+2]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                b[row][col+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col+i]);
                delete d;
                break;
            }
        }

        break;
    case 5: // middle normal component

        if(b[row][col-1]->number/10!=0)ThreeNum[0]=b[row][col-1]->number%10;
        ThreeNum[1]=b[row][col]->number%10;
        if(b[row][col+1]->number/10!=0)ThreeNum[2]=b[row][col+1]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    case 6: // rightest normal component

        if(b[row][col-2]->number/10!=0)ThreeNum[0]=b[row][col-2]->number%10;
        if(b[row][col-1]->number/10!=0)ThreeNum[1]=b[row][col-1]->number%10;
        ThreeNum[2]=b[row][col]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    }
}

void Three_H::eliminate(Blank *b[10][10], Blank *clicked)
{
    // garbage function
}

int Three_H::condition(Blank *b[10][10], Blank *focus)
{
    int row=focus->row;
    int col=focus->column;
    int num=focus->number;
    if(num!=0&&num!=5){
        if(num/10==0){ // control normal component
            // leftest condition
            if(col<=7&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))){
                return 1;
            }

            // moddle condition
            if(col>=1&&col<=8&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))){
                return 2;
            }

            // rightest condition
            if(col>=2&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))){
                return 3;
            }
        }
        else if(num/10!=0){ // control special component
            num/=10;
            // leftest condition
            if(col<=7&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))){
                return 4;
            }

            // moddle condition
            if(col>=1&&col<=8&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))){
                return 5;
            }

            // rightest condition
            if(col>=2&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))){
                return 6;
            }
        }
    }
    return 0;
}

Three_H::~Three_H()
{

}

