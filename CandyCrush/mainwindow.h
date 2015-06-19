#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "blank.h"
#include "destroy.h"

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
    void ReNewPicture();
    void MoveFillZero();
    bool EliminateLeftPossibility();
    void SpawnAfterEliminate();

public slots:
    void button_clicked(int row,int col);
    void ZeroVanish();

private:
    Ui::MainWindow *ui;
    Blank * b[10][10];
    Destroy * destroy;
    bool isClicked;
    int record_row;
    int record_column;
};

#endif // MAINWINDOW_H
