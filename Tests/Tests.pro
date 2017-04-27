include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    PhilosopherModel/forkTest.h \
    PhilosopherModel/philosopherMonitor.h \
    PhilosopherModel/philosopherTest.h

SOURCES +=     main.cpp
