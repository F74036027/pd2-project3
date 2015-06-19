#ifndef BLANK_H
#define BLANK_H

#include <QObject>
#include <QPushButton>
#include <QLabel>

class Blank : public QObject
{
    Q_OBJECT
public:
    explicit Blank(QWidget *parent, int Row, int Col);
    ~Blank();
    QPushButton * button;
    QTimer * time;
    void setRandonNumber();
    void setButtonPicture();
    void operator -(Blank * b);
    void operator |(Blank * b);
    const int row;
    const int column;
    int number;
signals:
    void Click(int row,int col);
    void MoveDone();

public slots:
    void click();
    void moveright();
    void moveleft();
    void movedown();
    void moveup();
private:
    int shift;
    //bool clicked;
};

#endif // BLANK_H
