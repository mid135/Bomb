#-------------------------------------------------
#
# Project created by QtCreator 2014-04-29T13:53:01
#
#-------------------------------------------------

QT       += core gui
QT       += opengl
INCLUDEPATH += -L/usr/lib/
INCLUDEPATH += -L/usr/lib64/
LIBS += -lsfml-graphics -lsfml-window -lsfml-system
QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bomberman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    elements.cpp \
    arena.cpp

HEADERS  += mainwindow.h \
    elements.h \
    config.h \
    arena.h

FORMS    += mainwindow.ui

