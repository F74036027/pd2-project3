#include "spawn5_b.h"
#include <QDebug>
#include "destroy.h"
#include "vertical.h"
#include "horizontal.h"
#include "nineblock.h"

Spawn5_B::Spawn5_B()
{

}

void Spawn5_B::spawn(Blank * b[10][10],Blank * clicked,int mode,int *score)
{
    int row=clicked->row;
    int col=clicked->column;
    int num=clicked->number;
    int FiveNum[5]={0};
    *score+=4;

    switch(mode){
    case 1: // left up normal component
        clicked->number=clicked->number*10+3;

        if(col<=8&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))){
            b[row][col+1]->number=0;
        }// right one condition
        if(row<=8&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
            b[row+1][col]->number=0;
        }// down one condition

        if(b[row][col-2]->number/10!=0)FiveNum[0]=b[row][col-2]->number%10;
        if(b[row][col-1]->number/10!=0)FiveNum[1]=b[row][col-1]->number%10;
        FiveNum[2]=b[row][col]->number;
        if(b[row-2][col]->number/10!=0)FiveNum[3]=b[row-2][col]->number%10;
        if(b[row-1][col]->number/10!=0)FiveNum[4]=b[row-1][col]->number%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col-2+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
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
    case 2: // left down normal component
        clicked->number=clicked->number*10+3;

        if(col<=8&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))){
            b[row][col+1]->number=0;
        }// right one condition
        if(row>=1&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
            b[row-1][col]->number=0;
        }// up one condition

        if(b[row][col-2]->number/10!=0)FiveNum[0]=b[row][col-2]->number%10;
        if(b[row][col-1]->number/10!=0)FiveNum[1]=b[row][col-1]->number%10;
        FiveNum[2]=b[row][col]->number;
        if(b[row+1][col]->number/10!=0)FiveNum[3]=b[row+1][col]->number%10;
        if(b[row+2][col]->number/10!=0)FiveNum[4]=b[row+2][col]->number%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col-2+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
            case 0:
                b[row+1+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            }
        }

        break;
    case 3: // right up normal component
        clicked->number=clicked->number*10+3;

        if(col>=1&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))){
            b[row][col-1]->number=0;
        }// left one condition
        if(row<=8&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
            b[row+1][col]->number=0;
        }// down one condition

        if(b[row][col+1]->number/10!=0)FiveNum[0]=b[row][col+1]->number%10;
        if(b[row][col+2]->number/10!=0)FiveNum[1]=b[row][col+2]->number%10;
        FiveNum[2]=b[row][col]->number;
        if(b[row-2][col]->number/10!=0)FiveNum[3]=b[row-2][col]->number%10;
        if(b[row-1][col]->number/10!=0)FiveNum[4]=b[row-1][col]->number%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col+1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
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
    case 4: // right down normal component
        clicked->number=clicked->number*10+3;

        if(col>=1&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))){
            b[row][col-1]->number=0;
        }// left one condition
        if(row>=1&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
            b[row-1][col]->number=0;
        }// up one condition

        if(b[row][col+1]->number/10!=0)FiveNum[0]=b[row][col+1]->number%10;
        if(b[row][col+2]->number/10!=0)FiveNum[1]=b[row][col+2]->number%10;
        FiveNum[2]=b[row][col]->number;
        if(b[row+1][col]->number/10!=0)FiveNum[3]=b[row+1][col]->number%10;
        if(b[row+2][col]->number/10!=0)FiveNum[4]=b[row+2][col]->number%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col+1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
            case 0:
                b[row+1+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            }
        }

        break;
    case 5: // left T normal component
        clicked->number=clicked->number*10+3;

        if(b[row][col-2]->number/10!=0)FiveNum[0]=b[row][col-2]->number%10;
        if(b[row][col-1]->number/10!=0)FiveNum[1]=b[row][col-1]->number%10;
        if(b[row-1][col]->number/10!=0)FiveNum[2]=b[row-1][col]->number%10;
        FiveNum[3]=b[row][col]->number;
        if(b[row+1][col]->number/10!=0)FiveNum[4]=b[row+1][col]->number%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col-2+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i+2]){
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
    case 6: // right T normal component
        clicked->number=clicked->number*10+3;

        if(b[row][col+1]->number/10!=0)FiveNum[0]=b[row][col+1]->number%10;
        if(b[row][col+2]->number/10!=0)FiveNum[1]=b[row][col+2]->number%10;
        if(b[row-1][col]->number/10!=0)FiveNum[2]=b[row-1][col]->number%10;
        FiveNum[3]=b[row][col]->number;
        if(b[row+1][col]->number/10!=0)FiveNum[4]=b[row+1][col]->number%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col+1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i+2]){
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
    case 7: // up T normal component
        clicked->number=clicked->number*10+3;

        if(b[row][col-1]->number/10!=0)FiveNum[0]=b[row][col-1]->number%10;
        FiveNum[1]=b[row][col]->number;
        if(b[row][col+1]->number/10!=0)FiveNum[2]=b[row][col+1]->number%10;
        if(b[row-2][col]->number/10!=0)FiveNum[3]=b[row-2][col]->number%10;
        if(b[row-1][col]->number/10!=0)FiveNum[4]=b[row-1][col]->number%10;

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col-1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-1+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-1+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-1+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
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
    case 8: // down T normal component
        clicked->number=clicked->number*10+3;

        if(b[row][col-1]->number/10!=0)FiveNum[0]=b[row][col-1]->number%10;
        FiveNum[1]=b[row][col]->number;
        if(b[row][col+1]->number/10!=0)FiveNum[2]=b[row][col+1]->number%10;
        if(b[row+1][col]->number/10!=0)FiveNum[3]=b[row+1][col]->number%10;
        if(b[row+2][col]->number/10!=0)FiveNum[4]=b[row+2][col]->number%10;

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col-1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-1+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-1+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-1+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
            case 0:
                b[row+1+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            }
        }

        break;
    case 9: // left up special component
        num/=10;

        if(col<=8&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))){
            b[row][col+1]->number=0;
        }// right one condition
        if(row<=8&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
            b[row+1][col]->number=0;
        }// down one condition

        if(b[row][col-2]->number/10!=0)FiveNum[0]=b[row][col-2]->number%10;
        if(b[row][col-1]->number/10!=0)FiveNum[1]=b[row][col-1]->number%10;
        FiveNum[2]=b[row][col]->number%10;
        if(b[row-2][col]->number/10!=0)FiveNum[3]=b[row-2][col]->number%10;
        if(b[row-1][col]->number/10!=0)FiveNum[4]=b[row-1][col]->number%10;

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col-2+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
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
    case 10: // left down special component
        num/=10;

        if(col<=8&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))){
            b[row][col+1]->number=0;
        }// right one condition
        if(row>=1&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
            b[row-1][col]->number=0;
        }// up one condition

        if(b[row][col-2]->number/10!=0)FiveNum[0]=b[row][col-2]->number%10;
        if(b[row][col-1]->number/10!=0)FiveNum[1]=b[row][col-1]->number%10;
        FiveNum[2]=b[row][col]->number%10;
        if(b[row+1][col]->number/10!=0)FiveNum[3]=b[row+1][col]->number%10;
        if(b[row+2][col]->number/10!=0)FiveNum[4]=b[row+2][col]->number%10;

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col-2+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
            case 0:
                b[row+1+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            }
        }

        break;
    case 11: // right up special component
        num/=10;

        if(col>=1&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))){
            b[row][col-1]->number=0;
        }// left one condition
        if(row<=8&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
            b[row+1][col]->number=0;
        }// down one condition

        if(b[row][col+1]->number/10!=0)FiveNum[0]=b[row][col+1]->number%10;
        if(b[row][col+2]->number/10!=0)FiveNum[1]=b[row][col+2]->number%10;
        FiveNum[2]=b[row][col]->number%10;
        if(b[row-1][col]->number/10!=0)FiveNum[3]=b[row-1][col]->number%10;
        if(b[row-2][col]->number/10!=0)FiveNum[4]=b[row-2][col]->number%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col+1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i+2]){
            case 0:
                b[row-i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row-i][col],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row-i][col],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row-i][col],score);
                delete d;
                break;
            }
        }

        break;
    case 12: // right down special component
        num/=10;

        if(col>=1&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))){
            b[row][col-1]->number=0;
        }// left one condition
        if(row>=1&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
            b[row-1][col]->number=0;
        }// up one condition

        if(b[row][col+1]->number/10!=0)FiveNum[0]=b[row][col+1]->number%10;
        if(b[row][col+2]->number/10!=0)FiveNum[1]=b[row][col+2]->number%10;
        FiveNum[2]=b[row][col]->number%10;
        if(b[row+1][col]->number/10!=0)FiveNum[3]=b[row+1][col]->number%10;
        if(b[row+2][col]->number/10!=0)FiveNum[4]=b[row+2][col]->number%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col+1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i+2]){
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
    case 13: // left T special component
        num/=10;

        if(b[row][col-2]->number/10!=0)FiveNum[0]=b[row][col-2]->number%10;
        if(b[row][col-1]->number/10!=0)FiveNum[1]=b[row][col-1]->number%10;
        if(b[row-1][col]->number/10!=0)FiveNum[2]=b[row-1][col]->number%10;
        FiveNum[3]=b[row][col]->number%10;
        if(b[row+1][col]->number/10!=0)FiveNum[4]=b[row+1][col]->number%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col-2+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-2+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i+2]){
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
    case 14: // right T special component
        num/=10;

        if(b[row][col+1]->number/10!=0)FiveNum[0]=b[row][col+1]->number%10;
        if(b[row][col+2]->number/10!=0)FiveNum[1]=b[row][col+2]->number%10;
        if(b[row-1][col]->number/10!=0)FiveNum[2]=b[row-1][col]->number%10;
        FiveNum[3]=b[row][col]->number%10;
        if(b[row+1][col]->number/10!=0)FiveNum[4]=b[row+1][col]->number%10;

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col+1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col+1+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i+2]){
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
    case 15: // up T special component
        num/=10;

        if(b[row][col-1]->number/10!=0)FiveNum[0]=b[row][col-1]->number%10;
        FiveNum[1]=b[row][col]->number%10;
        if(b[row][col+1]->number/10!=0)FiveNum[2]=b[row][col+1]->number%10;
        if(b[row-2][col]->number/10!=0)FiveNum[3]=b[row-2][col]->number%10;
        if(b[row-1][col]->number/10!=0)FiveNum[4]=b[row-1][col]->number%10;

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col-1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-1+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-1+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-1+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
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
    case 16: // down T special component
        num/=10;

        if(b[row][col-1]->number/10!=0)FiveNum[0]=b[row][col-1]->number%10;
        FiveNum[1]=b[row][col]->number%10;
        if(b[row][col+1]->number/10!=0)FiveNum[2]=b[row][col+1]->number%10;
        if(b[row+1][col]->number/10!=0)FiveNum[3]=b[row+1][col]->number%10;
        if(b[row+2][col]->number/10!=0)FiveNum[4]=b[row+2][col]->number%10;

        for(int i=0;i<=2;i++){
            Destroy * d;
            switch(FiveNum[i]){
            case 0:
                b[row][col-1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row][col-1+i],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row][col-1+i],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row][col-1+i],score);
                delete d;
                break;
            }
        }

        for(int i=0;i<2;i++){
            Destroy * d;
            switch(FiveNum[i+3]){
            case 0:
                b[row+1+i][col]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(b,b[row+1+i][col],score);
                delete d;
                break;
            }
        }

        break;
    default:
        qDebug()<<"Spawn5_B error";
    }
}

void Spawn5_B::eliminate(Blank *b[10][10],Blank * clicked,int *score)
{
    // garbage function
}

int Spawn5_B::condition(Blank *b[10][10], Blank *focus)
{
    int row=focus->row;
    int col=focus->column;
    int num=focus->number;
    if(num!=0&&num!=5){
        if(num/10==0){ // control normal component
            if(row>=2&&col>=2&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
                return 1;
            }// left up condition
            if(row<=7&&col>=2&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
                return 2;
            }// left down condition
            if(row>=2&&col<=7&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
                return 3;
            }// right up condition
            if(row<=7&&col<=7&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
                return 4;
            }// right down condition
            if(col>=2&&row>=1&&row<=8&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
                return 5;
            }// left T condition
            if(col<=7&&row>=1&&row<=8&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
                return 6;
            }// right T condition
            if(row>=2&&col>=1&&col<=8&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
                return 7;
            }// up T condition
            if(row<=7&&col>=1&&col<=8&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
                return 8;
            }// down T condition
        }
        else if(num/10!=0){ // control special component
            num/=10;
            if(row>=2&&col>=2&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
                return 9;
            }// left up condition
            if(row<=7&&col>=2&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
                return 10;
            }// left down condition
            if(row>=2&&col<=7&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
                return 11;
            }// right up condition
            if(row<=7&&col<=7&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
                return 12;
            }// right down condition
            if(col>=2&&row>=1&&row<=8&&((num==b[row][col-2]->number)||(num==b[row][col-2]->number/10))&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
                return 13;
            }// left T condition
            if(col<=7&&row>=1&&row<=8&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row][col+2]->number)||(num==b[row][col+2]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))){
                return 14;
            }// right T condition
            if(row>=2&&col>=1&&col<=8&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row-2][col]->number)||(num==b[row-2][col]->number/10))&&((num==b[row-1][col]->number)||(num==b[row-1][col]->number/10))){
                return 15;
            }// up T condition
            if(row<=7&&col>=1&&col<=8&&((num==b[row][col-1]->number)||(num==b[row][col-1]->number/10))&&((num==b[row][col+1]->number)||(num==b[row][col+1]->number/10))&&((num==b[row+1][col]->number)||(num==b[row+1][col]->number/10))&&((num==b[row+2][col]->number)||(num==b[row+2][col]->number/10))){
                return 16;
            }// down T condition

        }
    }
    return 0;
}

Spawn5_B::~Spawn5_B()
{

}

