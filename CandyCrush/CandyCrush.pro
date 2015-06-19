#-------------------------------------------------
#
# Project created by QtCreator 2015-06-11T22:56:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CandyCrush
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blank.cpp \
    destroy.cpp \
    spawn5.cpp \
    spawn4_v.cpp \
    spawn4_h.cpp \
    spawn5_b.cpp \
    all.cpp \
    one_color.cpp \
    nineblock.cpp \
    vertical.cpp \
    horizontal.cpp \
    three_h.cpp \
    three_v.cpp

HEADERS  += mainwindow.h \
    blank.h \
    destroy.h \
    spawn5.h \
    spawn4_v.h \
    spawn4_h.h \
    spawn5_b.h \
    all.h \
    one_color.h \
    nineblock.h \
    vertical.h \
    horizontal.h \
    three_h.h \
    three_v.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
