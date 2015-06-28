#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow),opened(false)
{
    ui->setupUi(this);
}

StartWindow::~StartWindow()
{
    delete ui;
    if(opened)delete w;
}

void StartWindow::on_pushButton_clicked()
{
    w=new MainWindow;
    opened=true;
    w->show();
    this->close();
}
