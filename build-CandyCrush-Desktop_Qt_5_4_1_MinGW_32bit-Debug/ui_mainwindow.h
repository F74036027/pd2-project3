/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *text1;
    QLabel *Score;
    QLabel *text2;
    QLabel *time_left;
    QLabel *StarPic;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        text1 = new QLabel(centralWidget);
        text1->setObjectName(QStringLiteral("text1"));
        text1->setGeometry(QRect(510, 0, 120, 80));
        QFont font;
        font.setFamily(QStringLiteral("Algerian"));
        font.setPointSize(20);
        text1->setFont(font);
        Score = new QLabel(centralWidget);
        Score->setObjectName(QStringLiteral("Score"));
        Score->setGeometry(QRect(620, 0, 170, 80));
        QFont font1;
        font1.setFamily(QStringLiteral("Algerian"));
        font1.setPointSize(24);
        Score->setFont(font1);
        Score->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        text2 = new QLabel(centralWidget);
        text2->setObjectName(QStringLiteral("text2"));
        text2->setGeometry(QRect(510, 80, 170, 80));
        text2->setFont(font1);
        time_left = new QLabel(centralWidget);
        time_left->setObjectName(QStringLiteral("time_left"));
        time_left->setGeometry(QRect(620, 80, 170, 80));
        time_left->setFont(font1);
        time_left->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        StarPic = new QLabel(centralWidget);
        StarPic->setObjectName(QStringLiteral("StarPic"));
        StarPic->setGeometry(QRect(500, 160, 300, 300));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        text1->setText(QApplication::translate("MainWindow", "SCORE:", 0));
        Score->setText(QApplication::translate("MainWindow", "0", 0));
        text2->setText(QApplication::translate("MainWindow", "Time:", 0));
        time_left->setText(QApplication::translate("MainWindow", "60", 0));
        StarPic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
