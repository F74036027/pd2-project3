/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QStringLiteral("StartWindow"));
        StartWindow->resize(800, 500);
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 280, 391, 171));
        QFont font;
        font.setFamily(QStringLiteral("Algerian"));
        font.setPointSize(72);
        pushButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 70, 201, 111));
        QFont font1;
        font1.setFamily(QStringLiteral("Algerian"));
        font1.setPointSize(28);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 190, 221, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Algerian"));
        font2.setPointSize(22);
        label_2->setFont(font2);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(410, 200, 241, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("Algerian"));
        font3.setPointSize(24);
        label_3->setFont(font3);
        StartWindow->setCentralWidget(centralwidget);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QApplication::translate("StartWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("StartWindow", "START", 0));
        label->setText(QApplication::translate("StartWindow", "TARGET:", 0));
        label_2->setText(QApplication::translate("StartWindow", "1000 points", 0));
        label_3->setText(QApplication::translate("StartWindow", "in 1 minute", 0));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
