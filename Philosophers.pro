#-------------------------------------------------
#
# Project created by QtCreator 2017-04-14T10:44:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Philosophers
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    canteen.cpp \
    philosopher.cpp

HEADERS  += mainwindow.h \
    canteen.h \
    philosopher.h

FORMS    += mainwindow.ui
