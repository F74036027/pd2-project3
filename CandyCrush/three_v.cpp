#include "three_v.h"
#include <QDebug>
#include "destroy.h"
#include "horizontal.h"
#include "vertical.h"
#include "nineblock.h"

Three_V::Three_V()
{

}

void Three_V::spawn(Blank * b[10][10],Blank * clicked,int mode,int *score)
{
    int row=clicked->row;
    int col=clicked->column;
    Destroy * d;
    int ThreeNum[3]={0};
    *score+=3;

    switch(mode){
    case 1: // topest normal component
        clicked->number=0;

        ThreeNum[0]=b[row][col]->number;
        if(b[row+1][col]->number/10!=0)ThreeNum[1]=b[row+1][col]->number%10;
        if(b[row+2][col]->number/10!=0)ThreeNum[2]=b[row+2][col]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                b[row+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row+i][col],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row+i][col],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row+i][col],score);
                delete d;
                break;
            }
        }

        break;
    case 2: // middle normal component
        clicked->number=0;

        if(b[row-1][col]->number/10!=0)ThreeNum[0]=b[row-1][col]->number%10;
        ThreeNum[1]=b[row][col]->number;
        if(b[row+1][col]->number/10!=0)ThreeNum[2]=b[row+1][col]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                b[row-1+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row-1+i][col],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row-1+i][col],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row-1+i][col],score);
                delete d;
                break;
            }
        }

        break;
    case 3: // downest normal component
        clicked->number=0;

        if(b[row-2][col]->number/10!=0)ThreeNum[0]=b[row-2][col]->number%10;
        if(b[row-1][col]->number/10!=0)ThreeNum[1]=b[row-1][col]->number%10;
        ThreeNum[2]=b[row][col]->number;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                b[row-2+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row-2+i][col],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row-2+i][col],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row-2+i][col],score);
                delete d;
                break;
            }
        }

        break;
    case 4: // topest special component

        ThreeNum[0]=b[row][col]->number%10;
        if(b[row+1][col]->number/10!=0)ThreeNum[1]=b[row+1][col]->number%10;
        if(b[row+2][col]->number/10!=0)ThreeNum[2]=b[row+2][col]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                b[row+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row+i][col],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row+i][col],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row+i][col],score);
                delete d;
                break;
            }
        }
        break;
    case 5: // middle special component

        if(b[row-1][col]->number/10!=0)ThreeNum[0]=b[row-1][col]->number%10;
        ThreeNum[1]=b[row][col]->number%10;
        if(b[row+1][col]->number/10!=0)ThreeNum[2]=b[row+1][col]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                b[row-1+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row-1+i][col],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row-1+i][col],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row-1+i][col],score);
                delete d;
                break;
            }
        }

        break;
    case 6: // downest special component

        if(b[row-2][col]->number/10!=0)ThreeNum[0]=b[row-2][col]->number%10;
        if(b[row-1][col]->number/10!=0)ThreeNum[1]=b[row-1][col]->number%10;
        ThreeNum[2]=b[row][col]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                b[row-2+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row-2+i][col],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row-2+i][col],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row-2+i][col],score);
                delete d;
                break;
            }
        }

        break;
    }
}

void Three_V::eliminate(Blank *b[10][10], Blank *clicked,int *score)
{
    // garbage function
}

int Three_V::condition(Blank *b[10][10], Blank *focus)
{
    int row=focus->row;
    int col=focus->column;
    int num=focus->number;
    if(num!=0&&num!=5){
        if(num/10==0){ // control normal component
            // topest condition
            if(row<=7&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
                return 1;
            }

            // moddle condition
            if(row>=1&&row<=8&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
                return 2;
            }

            // downest condition
            if(row>=2&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
                return 3;
            }
        }
        else if(num/10!=0){ // control special component
            num/=10;
            // topest condition
            if(row<=7&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
                return 4;
            }

            // moddle condition
            if(row>=1&&row<=8&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
                return 5;
            }

            // downest condition
            if(row>=2&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
                return 6;
            }
        }
    }
    return 0;
}

Three_V::~Three_V()
{

}

