#-------------------------------------------------
#
# Project created by QtCreator 2014-09-25T20:44:39
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ledcube
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cubeeffect.cpp \
    eventtransmitter.cpp \
    console.cpp \
    portconnector.cpp \
    effectcatalog.cpp \
    commandqueue.cpp \
    consolecommand.cpp \
    connectorcommand.cpp

HEADERS  += mainwindow.h \
    cubeeffect.h \
    eventtransmitter.h \
    command.h \
    console.h \
    portconnector.h \
    effectcatalog.h \
    commandqueue.h \
    consolecommand.h \
    connectorcommand.h

FORMS    += mainwindow.ui \
    effectcatalog.ui
