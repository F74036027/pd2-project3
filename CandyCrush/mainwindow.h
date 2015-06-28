#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "blank.h"
#include "destroy.h"
#include <QTimer>
#include <QString>
#include <string>
#include "gameover.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void GameStart();
    void setClickedPicture(Blank * b);
    bool Judge(int row1,int col1,int row2,int col2);
    bool JudgeSpawn5(int row,int col);
    bool JudgeSpawn5_B(int row,int col);
    bool JudgeSpawn4_V(int row,int col);
    bool JudgeSpawn4_H(int row,int col);
    bool JudgeThree_V(int row,int col);
    bool JudgeThree_H(int row,int col);
    void ReNewPicture(); // show new status
    void MoveFillZero(); // go down to fill zero
    bool EliminateLeftPossibility(); // after fill eliminate
    void SpawnAfterEliminate(); // get the new number
    bool CanChange(); // test if the new map can play
    void ReNewMap(); // if cannot play , respawn

public slots:
    void button_clicked(int row,int col);
    void ZeroVanish();
    void MinusTime();

private:
    Ui::MainWindow *ui;
    Blank * b[10][10];
    Destroy * destroy;
    bool isClicked;
    int record_row;
    int record_column;
    bool OnOff;
    int score;
    int * scorePtr;
    int time_lost;
    QTimer * t;
    QString ScoreString;
    QString TimeString;
    GameOver * G;
    bool GG;
};

#endif // MAINWINDOW_H
