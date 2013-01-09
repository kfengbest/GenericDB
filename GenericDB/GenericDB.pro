#-------------------------------------------------
#
# Project created by QtCreator 2013-01-09T21:10:36
#
#-------------------------------------------------

QT       += core gui

INCLUDEPATH += /Users/fengka/Src/GenericDB/3P/sqlite/3.6/src
LIBS += /Users/fengka/Src/GenericDB/3P/sqlite/3.6/lib/mac/64/debug/libsqlite3.a

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GenericDB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
