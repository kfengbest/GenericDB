#-------------------------------------------------
#
# Project created by QtCreator 2013-01-09T21:10:36
#
#-------------------------------------------------

QT       += core gui

INCLUDEPATH += ../3P/sqlite/3.6/src
LIBS += ../3P/sqlite/3.6/lib/mac/64/debug/libsqlite3.a

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GenericDB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbtable.cpp \
    dbview.cpp \
    connectionsqlite.cpp \
    connectionmssql.cpp \
    connectionbase.cpp \
    connectionmysql.cpp \
    connectionfactory.cpp \
    dbrecordbuffer.cpp \
    dbfield.cpp

HEADERS  += mainwindow.h \
    dbtable.h \
    dbview.h \
    connectionsqlite.h \
    connectionmssql.h \
    connectionbase.h \
    connectionmysql.h \
    connectionfactory.h \
    dbrecordbuffer.h \
    dbfield.h

FORMS    += mainwindow.ui
