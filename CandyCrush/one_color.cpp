#include "one_color.h"
#include <QDebug>
#include "destroy.h"
#include "vertical.h"
#include "horizontal.h"
#include "nineblock.h"

One_Color::One_Color()
{

}

void One_Color::spawn(Blank * b[10][10],Blank * clicked,int mode,int *score)
{
    // garbage function
}

void One_Color::eliminate(Blank *b[10][10], Blank *clicked,int *score)
{
    int destroy_color;
    int num_copy[10][10];
    Destroy * d;

    if(clicked->number!=0){

        if(clicked->number/10==0)destroy_color=clicked->number;
        else{destroy_color=clicked->number/10;}

        // copy
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                num_copy[i][j]=b[i][j]->number;
            }
        } // end copy

        // use copy to destroy
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(num_copy[i][j]==destroy_color){
                    b[i][j]->number=0;
                    *score++;
                }
                else if((num_copy[i][j]/10!=0)&&(num_copy[i][j]/10==destroy_color)){
                    switch (num_copy[i][j]%10) {
                    case 1: // vertical bomb
                        d=new Vertical;
                        d->eliminate(b,b[i][j],score);
                        delete d;
                        break;
                    case 2: // horizontal bomb
                        d=new Horizontal;
                        d->eliminate(b,b[i][j],score);
                        delete d;
                        break;
                    case 3: // bomb
                        d=new NineBlock;
                        d->eliminate(b,b[i][j],score);
                        delete d;
                        break;
                    default:
                        qDebug()<<"eliminate one color error";
                    }
                }
            }
        } // end use copy
    }
}

int One_Color::condition(Blank *b[10][10], Blank *focus)
{
    // garbage function
}

One_Color::~One_Color()
{

}

