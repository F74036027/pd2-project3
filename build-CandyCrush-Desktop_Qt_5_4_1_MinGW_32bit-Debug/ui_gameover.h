/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOver
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *scorePic;
    QLabel *starPic;

    void setupUi(QMainWindow *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName(QStringLiteral("GameOver"));
        GameOver->resize(800, 500);
        centralwidget = new QWidget(GameOver);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 20, 300, 100));
        QFont font;
        font.setFamily(QStringLiteral("Algerian"));
        font.setPointSize(24);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 140, 281, 101));
        label_2->setFont(font);
        scorePic = new QLabel(centralwidget);
        scorePic->setObjectName(QStringLiteral("scorePic"));
        scorePic->setGeometry(QRect(430, 150, 141, 71));
        scorePic->setFont(font);
        scorePic->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        starPic = new QLabel(centralwidget);
        starPic->setObjectName(QStringLiteral("starPic"));
        starPic->setGeometry(QRect(270, 270, 271, 161));
        starPic->setFont(font);
        GameOver->setCentralWidget(centralwidget);

        retranslateUi(GameOver);

        QMetaObject::connectSlotsByName(GameOver);
    } // setupUi

    void retranslateUi(QMainWindow *GameOver)
    {
        GameOver->setWindowTitle(QApplication::translate("GameOver", "MainWindow", 0));
        label->setText(QApplication::translate("GameOver", "Time is UP!!!!", 0));
        label_2->setText(QApplication::translate("GameOver", "Your Score:", 0));
        scorePic->setText(QString());
        starPic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
