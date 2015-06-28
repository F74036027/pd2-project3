#include "mainwindow.h"
#include "startwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    w.show();
    w.setFixedSize(800,500);

    return a.exec();
}
