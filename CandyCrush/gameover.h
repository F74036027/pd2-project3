#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class GameOver;
}

class GameOver : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent,int scoreNum,int starNum);
    ~GameOver();

private:
    Ui::GameOver *ui;
    QString scoreStr;
    int score;
    int star;
signals:
    void quit(int,int);
};

#endif // GAMEOVER_H
