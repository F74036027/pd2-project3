#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include "all.h"
#include "one_color.h"
#include "nineblock.h"
#include "spawn5.h"
#include "spawn5_b.h"
#include "spawn4_v.h"
#include "spawn4_h.h"
#include "vertical.h"
#include "horizontal.h"
#include "three_h.h"
#include "three_v.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            b[i][j]=new Blank(this,i,j);
            connect(b[i][j],SIGNAL(Click(int,int)),this,SLOT(button_clicked(int,int)));
            connect(b[i][j],SIGNAL(MoveDone()),this,SLOT(ZeroVanish()));
        }
    }
    srand(time(NULL));
    isClicked=false;
    GG=false;
    OnOff=true;
    score=0;
    scorePtr=&score;

    time_lost=60;
    t=new QTimer();

    GameStart();
}

MainWindow::~MainWindow()
{
    delete ui;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            delete b[i][j];
        }
    }
    delete t;
    if(GG)delete G;
}

void MainWindow::GameStart()
{
    isClicked=false;
    OnOff=true;

    score=0;
    ScoreString=QString::number(score,10);
    ui->Score->setText(ScoreString);

    time_lost=60;
    TimeString=QString::number(time_lost,10);
    ui->time_left->setText(TimeString);

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            b[i][j]->setRandonNumber();
            b[i][j]->setButtonPicture();
            if(j>=2&&((b[i][j]->number)==(b[i][j-1]->number))&&((b[i][j]->number)==(b[i][j-2]->number))){ // check row
               j--;
            }
            if(i>=2&&((b[i][j]->number)==(b[i-1][j]->number))&&((b[i][j]->number)==(b[i-2][j]->number))){ // check column
               j--;
            }
        }
    }
    if(!CanChange()){
        ReNewMap();
    }

    connect(t,SIGNAL(timeout()),this,SLOT(MinusTime()));
    t->start(1000);
}

void MainWindow::setClickedPicture(Blank * b)
{
    // 1 red, 2 yellow, 3 green, 4 blue
    if(!isClicked){
        switch(b->number){
            case 1:
                b->button->setIcon(QIcon(QPixmap(":/pic/red_clicked.png")));
                break;
            case 11:
                b->button->setIcon(QIcon(QPixmap(":/pic/red_vertical_bomb_clicked.png")));
                break;
            case 12:
                b->button->setIcon(QIcon(QPixmap(":/pic/red_horizontal_bomb_clicked.png")));
                break;
            case 13:
                b->button->setIcon(QIcon(QPixmap(":/pic/red_bomb_clicked.png")));
                break;
            case 2:
                b->button->setIcon(QIcon(QPixmap(":/pic/yellow_clicked.png")));
                break;
            case 21:
                b->button->setIcon(QIcon(QPixmap(":/pic/yellow_vertical_bomb_clicked.png")));
                break;
            case 22:
                b->button->setIcon(QIcon(QPixmap(":/pic/yellow_horizontal_bomb_clicked.png")));
                break;
            case 23:
                b->button->setIcon(QIcon(QPixmap(":/pic/yellow_bomb_clicked.png")));
                break;
            case 3:
                b->button->setIcon(QIcon(QPixmap(":/pic/green_clicked.png")));
                break;
            case 31:
                b->button->setIcon(QIcon(QPixmap(":/pic/green_vertical_bomb_clicked.png")));
                break;
            case 32:
                b->button->setIcon(QIcon(QPixmap(":/pic/green_horizontal_bomb_clicked.png")));
                break;
            case 33:
                b->button->setIcon(QIcon(QPixmap(":/pic/green_bomb_clicked.png")));
                break;
            case 4:
                b->button->setIcon(QIcon(QPixmap(":/pic/blue_clicked.png")));
                break;
            case 41:
                b->button->setIcon(QIcon(QPixmap(":/pic/blue_vertical_bomb_clicked.png")));
                break;
            case 42:
                b->button->setIcon(QIcon(QPixmap(":/pic/blue_horizontal_bomb_clicked.png")));
                break;
            case 43:
                b->button->setIcon(QIcon(QPixmap(":/pic/blue_bomb_clicked.png")));
                break;
            case 5:
                b->button->setIcon(QIcon(QPixmap(":/pic/power_bomb_clicked.png")));
                break;
        }
    }
    else{
        b->setButtonPicture();
    }
    return;
}

bool MainWindow::Judge(int row1,int col1,int row2,int col2)
{
    bool AnythingDone[12]={0};

    // check destroy all
    if((b[row1][col1]->number==5)&&(b[row2][col2]->number==5)){
        destroy=new All;
        destroy->eliminate(b,b[row1][col1],scorePtr);
        delete destroy;
        return true;
    }
    // end check destroy all

    // check destroy one color
    if((b[row1][col1]->number==5)||(b[row2][col2]->number==5)){
        if(b[row1][col1]->number==5){
            destroy=new One_Color;
            destroy->eliminate(b,b[row2][col2],scorePtr);
            delete destroy;
            return true;
        }
        if(b[row2][col2]->number==5){
            destroy=new One_Color;
            destroy->eliminate(b,b[row1][col1],scorePtr);
            delete destroy;
            return true;
        }
    }// end check destroy one color

    // check spawn power bomb
    AnythingDone[0]=JudgeSpawn5(row1,col1);
    AnythingDone[1]=JudgeSpawn5(row2,col2);
    // end check spawn power bomb

    // check spawn bomb
    AnythingDone[2]=JudgeSpawn5_B(row1,col1);
    AnythingDone[3]=JudgeSpawn5_B(row2,col2);
    // end check spawn bomb

    // check spawn vertical bomb
    AnythingDone[4]=JudgeSpawn4_V(row1,col1);
    AnythingDone[5]=JudgeSpawn4_V(row2,col2);
    // end check spawn vertical bomb

    // check spawn horizontal bomb
    AnythingDone[6]=JudgeSpawn4_H(row1,col1);
    AnythingDone[7]=JudgeSpawn4_H(row2,col2);
    // end check spawn horizontal bomb

    // check destroy vertical 3
    AnythingDone[8]=JudgeThree_V(row1,col1);
    AnythingDone[9]=JudgeThree_V(row2,col2);
    // end check destroy horizontal 3

    // check destroy vertical 3
    AnythingDone[10]=JudgeThree_H(row1,col1);
    AnythingDone[11]=JudgeThree_H(row2,col2);
    // end check destroy horizontal 3

    for(int i=0;i<12;i++){
        if(AnythingDone[i]==true)
            return true;
    }
    return false;
}

bool MainWindow::JudgeSpawn5(int row, int col)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Spawn5;
    return_value=destroy->condition(b,b[row][col]);
    if(return_value){
        switch(return_value){
        case 1: // vertical normal component
            destroy->spawn(b,b[row][col],1,scorePtr);
            AnySpawn=true;
            break;
        case 2: // horizontal normal component
            destroy->spawn(b,b[row][col],2,scorePtr);
            AnySpawn=true;
            break;
        case 3: // vertical special component
            destroy->spawn(b,b[row][col],3,scorePtr);
            AnySpawn=true;
            break;
        case 4: // horizontal special component
            destroy->spawn(b,b[row][col],4,scorePtr);
            AnySpawn=true;
            break;
        default:
            qDebug()<<"JudgeSpawn5 error";
        }
    }
    delete destroy;
    return AnySpawn;
}

bool MainWindow::JudgeSpawn5_B(int row, int col)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Spawn5_B;
    return_value=destroy->condition(b,b[row][col]);
    if(return_value){
        switch(return_value){
        case 1: // left up normal component
            destroy->spawn(b,b[row][col],1,scorePtr);
            AnySpawn=true;
            break;
        case 2: // left down normal component
            destroy->spawn(b,b[row][col],2,scorePtr);
            AnySpawn=true;
            break;
        case 3: // right up normal component
            destroy->spawn(b,b[row][col],3,scorePtr);
            AnySpawn=true;
            break;
        case 4: // right down normal component
            destroy->spawn(b,b[row][col],4,scorePtr);
            AnySpawn=true;
            break;
        case 5: // left T normal component
            destroy->spawn(b,b[row][col],5,scorePtr);
            AnySpawn=true;
            break;
        case 6: // right T normal component
            destroy->spawn(b,b[row][col],6,scorePtr);
            AnySpawn=true;
            break;
        case 7: // up T normal component
            destroy->spawn(b,b[row][col],7,scorePtr);
            AnySpawn=true;
            break;
        case 8: // down T normal component
            destroy->spawn(b,b[row][col],8,scorePtr);
            AnySpawn=true;
            break;
        case 9: // left up special component
            destroy->spawn(b,b[row][col],9,scorePtr);
            AnySpawn=true;
            break;
        case 10: // left down special component
            destroy->spawn(b,b[row][col],10,scorePtr);
            AnySpawn=true;
            break;
        case 11: // right up special component
            destroy->spawn(b,b[row][col],11,scorePtr);
            AnySpawn=true;
            break;
        case 12: // right down special component
            destroy->spawn(b,b[row][col],12,scorePtr);
            AnySpawn=true;
            break;
        case 13: // left T special component
            destroy->spawn(b,b[row][col],13,scorePtr);
            AnySpawn=true;
            break;
        case 14: // right T special component
            destroy->spawn(b,b[row][col],14,scorePtr);
            AnySpawn=true;
            break;
        case 15: // up T special component
            destroy->spawn(b,b[row][col],15,scorePtr);
            AnySpawn=true;
            break;
        case 16: // down T special component
            destroy->spawn(b,b[row][col],16,scorePtr);
            AnySpawn=true;
            break;
        default:
            qDebug()<<"JudgeSpawn5_B error";
        }
    }
    delete destroy;
    return AnySpawn;
}

bool MainWindow::JudgeSpawn4_V(int row, int col)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Spawn4_V;
    return_value=destroy->condition(b,b[row][col]);
    if(return_value){
        switch(return_value){
        case 1: // O normal component
                // X
                // O
                // O
            destroy->spawn(b,b[row][col],1,scorePtr);
            AnySpawn=true;
            break;
        case 2: // O normal component
                // O
                // X
                // O
            destroy->spawn(b,b[row][col],2,scorePtr);
            AnySpawn=true;
            break;
        case 3: // O special component
                // X
                // O
                // O
            destroy->spawn(b,b[row][col],3,scorePtr);
            AnySpawn=true;
            break;
        case 4: // O special component
                // O
                // X
                // O
            destroy->spawn(b,b[row][col],4,scorePtr);
            AnySpawn=true;
            break;
        default:
            qDebug()<<"JudgeSpawn4_H error";
        }
    }
    delete destroy;
    return AnySpawn;
}

bool MainWindow::JudgeSpawn4_H(int row, int col)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Spawn4_H;
    return_value=destroy->condition(b,b[row][col]);
    if(return_value){
        switch(return_value){
        case 1: // OXOO normal component
            destroy->spawn(b,b[row][col],1,scorePtr);
            AnySpawn=true;
            break;
        case 2: // OOXO normal component
            destroy->spawn(b,b[row][col],2,scorePtr);
            AnySpawn=true;
            break;
        case 3: // OOXO special component
            destroy->spawn(b,b[row][col],3,scorePtr);
            AnySpawn=true;
            break;
        case 4: // OOXO special component
            destroy->spawn(b,b[row][col],4,scorePtr);
            AnySpawn=true;
            break;
        default:
            qDebug()<<"JudgeSpawn4_H error";
        }
    }
    delete destroy;
    return AnySpawn;
}

bool MainWindow::JudgeThree_V(int row, int col)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Three_V;
    return_value=destroy->condition(b,b[row][col]);
    if(return_value){
        switch(return_value){
        case 1: // topest normal component
            if(OnOff)destroy->spawn(b,b[row][col],1,scorePtr);
            AnySpawn=true;
            break;
        case 2: // middle normal component
            if(OnOff)destroy->spawn(b,b[row][col],2,scorePtr);
            AnySpawn=true;
            break;
        case 3: // downest special component
            if(OnOff)destroy->spawn(b,b[row][col],3,scorePtr);
            AnySpawn=true;
            break;
        case 4: // topest special component
            if(OnOff)destroy->spawn(b,b[row][col],4,scorePtr);
            AnySpawn=true;
            break;
        case 5: // middle special component
            if(OnOff)destroy->spawn(b,b[row][col],5,scorePtr);
            AnySpawn=true;
            break;
        case 6: // downest special component
            if(OnOff)destroy->spawn(b,b[row][col],6,scorePtr);
            AnySpawn=true;
            break;
        default:
            qDebug()<<"JudgeThree_V error";
        }
    }
    delete destroy;
    return AnySpawn;
}

bool MainWindow::JudgeThree_H(int row, int col)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Three_H;
    return_value=destroy->condition(b,b[row][col]);
    if(return_value){
        switch(return_value){
        case 1: // leftest normal component
            if(OnOff)destroy->spawn(b,b[row][col],1,scorePtr);
            AnySpawn=true;
            break;
        case 2: // middle normal component
            if(OnOff)destroy->spawn(b,b[row][col],2,scorePtr);
            AnySpawn=true;
            break;
        case 3: // rightest special component
            if(OnOff)destroy->spawn(b,b[row][col],3,scorePtr);
            AnySpawn=true;
            break;
        case 4: // leftest special component
            if(OnOff)destroy->spawn(b,b[row][col],4,scorePtr);
            AnySpawn=true;
            break;
        case 5: // middle special component
            if(OnOff)destroy->spawn(b,b[row][col],5,scorePtr);
            AnySpawn=true;
            break;
        case 6: // rightest special component
            if(OnOff)destroy->spawn(b,b[row][col],6,scorePtr);
            AnySpawn=true;
            break;
        default:
            qDebug()<<"JudgeThree_V error";
        }
    }
    delete destroy;
    return AnySpawn;
}

void MainWindow::ZeroVanish()
{
    while(1){
        bool All_Destroy=false;
        MoveFillZero();
        All_Destroy=!EliminateLeftPossibility();
        if(All_Destroy){
            break;
        }
    }
    SpawnAfterEliminate();

    if(!CanChange()){
        ReNewMap();
    }

    ReNewPicture();
}

void MainWindow::MinusTime()
{
    time_lost--;

    TimeString=QString::number(time_lost,10);
    ui->time_left->setText(TimeString);

    if(time_lost==0){
        t->stop();
        disconnect(t,SIGNAL(timeout()),this,SLOT(MinusTime()));
        int S;
        if(score<300)S=0;
        else if(score<600)S=1;
        else if(score<1000)S=2;
        else if(score>=1000)S=3;

        G=new GameOver(this,score,S);
        G->show();
        GG=true;
        //this->close();
    }

}

void MainWindow::button_clicked(int row,int col)
{qDebug()<<(b[row][col]->number);
    if(!isClicked){
       setClickedPicture(b[row][col]);
       record_row=row;
       record_column=col;
       isClicked=true;
    }
    else{
       if(record_row==row&&record_column==col+1){
           *b[row][col]-b[row][col+1]; // change
           if(!Judge(row,col,record_row,record_column)){
               *b[row][col]-b[row][col+1]; // nothing done
           }
       }
       else if(record_row==row&&record_column==col-1){
           *b[row][col-1]-b[row][col]; // change
           if(!Judge(row,col,record_row,record_column)){
               *b[row][col-1]-b[row][col]; // nothing done
           }
       }
       else if(record_row==row+1&&record_column==col){
           *b[row][col]|b[row+1][col]; // change
           if(!Judge(row,col,record_row,record_column)){
               *b[row][col]|b[row+1][col]; // nothing done
           }
       }
       else if(record_row==row-1&&record_column==col){
           *b[row-1][col]|b[row][col]; // change
           if(!Judge(row,col,record_row,record_column)){
               *b[row-1][col]|b[row][col]; // nothing done
           }
       }
       else{
           setClickedPicture(b[record_row][record_column]);
       }
       isClicked=false;
    }
    return;
}

void MainWindow::ReNewPicture()
{
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            b[i][j]->setButtonPicture();
        }
    }

    ScoreString=QString::number(score,10);
    ui->Score->setText(ScoreString);

    if(score>=300)ui->StarPic->setPixmap(QPixmap(":/pic/star1.png"));
    if(score>=600)ui->StarPic->setPixmap(QPixmap(":/pic/star2.png"));
    if(score>=1000)ui->StarPic->setPixmap(QPixmap(":/pic/star3.png"));
}

void MainWindow::MoveFillZero()
{
    // move all blocks to fill in zeros
    for(int i=9;i>=0;i--){
        for(int j=9;j>=0;j--){
            for(int k=i-1;k>=0;k--){
                if(i!=0&&b[i][j]->number==0&&b[k][j]->number!=0){
                    b[i][j]->number=b[k][j]->number;
                    b[k][j]->number=0;
                }
            }
        }
    } // end move
}

bool MainWindow::EliminateLeftPossibility()
{
    bool Still_Can_Eliminate=false;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(Still_Can_Eliminate=JudgeSpawn5(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(Still_Can_Eliminate=JudgeSpawn5_B(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(Still_Can_Eliminate=JudgeSpawn4_V(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(Still_Can_Eliminate=JudgeSpawn4_H(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(Still_Can_Eliminate=JudgeThree_V(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(Still_Can_Eliminate=JudgeThree_H(i,j))return true;
        }
    }

    return Still_Can_Eliminate;
}

void MainWindow::SpawnAfterEliminate()
{
    // spawn new number for zeros
    for(int i=9;i>=0;i--){
        for(int j=9;j>=0;j--){
            if(b[i][j]->number==0){
                b[i][j]->setRandonNumber();
                if(j>=2&&((b[i][j]->number==b[i][j-2]->number)||(b[i][j]->number==b[i][j-2]->number%10))&&((b[i][j]->number==b[i][j-1]->number)||(b[i][j]->number==b[i][j-1]->number%10))){
                    b[i][j]->number=0;
                    j++;
                }//left condition
                else if(j<=7&&((b[i][j]->number==b[i][j+1]->number)||(b[i][j]->number==b[i][j+1]->number%10))&&((b[i][j]->number==b[i][j+2]->number)||(b[i][j]->number==b[i][j+2]->number%10))){
                    b[i][j]->number=0;
                    j++;
                }//right condition
                else if(i<=7&&((b[i][j]->number==b[i+1][j]->number)||(b[i][j]->number==b[i+1][j]->number%10))&&((b[i][j]->number==b[i+2][j]->number)||(b[i][j]->number==b[i+2][j]->number))){
                    b[i][j]->number=0;
                    j++;
                }//down condition
                else if(j>=1&&j<=8&&((b[i][j]->number==b[i][j-1]->number)||(b[i][j]->number==b[i][j-1]->number%10))&&((b[i][j]->number==b[i][j+1]->number)||(b[i][j]->number==b[i][j+1]->number%10))){
                    b[i][j]->number=0;
                    j++;
                }//middle condition
            }
        }
    }// end spawn
    ReNewPicture();
}

bool MainWindow::CanChange()
{
    OnOff=false;// close the ability to eliminate

    for(int i=0;i<10;i++){ // if three H can eliminate
        for(int j=0;j<9;j++){
            int tmp_number=b[i][j]->number;
            b[i][j]->number=b[i][j+1]->number;
            b[i][j+1]->number=tmp_number;
            if(JudgeThree_H(i,j) || JudgeThree_H(i,j+1)){
                OnOff=true;
                tmp_number=b[i][j]->number;
                b[i][j]->number=b[i][j+1]->number;
                b[i][j+1]->number=tmp_number;
                return true;
            }
            tmp_number=b[i][j]->number;
            b[i][j]->number=b[i][j+1]->number;
            b[i][j+1]->number=tmp_number;
        }
    }

    for(int j=0;j<10;j++){
        for(int i=0;i<9;i++){
            int tmp_number=b[i][j]->number;
            b[i][j]->number=b[i+1][j]->number;
            b[i+1][j]->number=tmp_number;
            if(JudgeThree_V(i,j) || JudgeThree_V(i+1,j)){
                OnOff=true;
                tmp_number=b[i][j]->number;
                b[i][j]->number=b[i+1][j]->number;
                b[i+1][j]->number=tmp_number;
                return true;
            }
            tmp_number=b[i][j]->number;
            b[i][j]->number=b[i+1][j]->number;
            b[i+1][j]->number=tmp_number;
        }
    }

    return false;
}

void MainWindow::ReNewMap()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            b[i][j]->number=0;
        }
    } // initialize

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            b[i][j]->setRandonNumber();
            b[i][j]->setButtonPicture();
            if(j>=2&&((b[i][j]->number)==(b[i][j-1]->number))&&((b[i][j]->number)==(b[i][j-2]->number))){ // check row
               j--;
            }
            if(i>=2&&((b[i][j]->number)==(b[i-1][j]->number))&&((b[i][j]->number)==(b[i-2][j]->number))){ // check column
               j--;
            }
        }
    } // re-spawn

    if(!CanChange()){
        ReNewMap();
    }

    return;
}

/*
void MainWindow::on_pushButton_clicked()
{
    t->stop();
    disconnect(t,SIGNAL(timeout()),this,SLOT(MinusTime()));
    GameStart();
}*/
