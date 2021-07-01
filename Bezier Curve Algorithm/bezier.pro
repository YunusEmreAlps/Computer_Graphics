#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T23:58:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bezier
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    resim.cpp \
    nokta.cpp

HEADERS  += mainwindow.h \
    resim.h \
    nokta.h

FORMS    += mainwindow.ui

RESOURCES += \
    resimler.qrc
