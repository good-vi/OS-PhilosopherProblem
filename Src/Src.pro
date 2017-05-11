#-------------------------------------------------
#
# Project created by QtCreator 2017-04-14T10:44:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Philosophers
TEMPLATE = app


SOURCES += main.cpp \
    GUI/mainwindow.cpp \
    PhilosopherModel/philosopher.cpp \
    PhilosopherModel/canteen.cpp \
    PhilosopherModel/philosopherMonitor.cpp

HEADERS  += \ 
    GUI/mainwindow.h \
    PhilosopherModel/philosopher.h \
    PhilosopherModel/canteen.h \
    PhilosopherModel/philosopherMonitor.h

FORMS    += \ 
    GUI/mainwindow.ui

CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14
