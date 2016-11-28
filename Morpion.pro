#-------------------------------------------------
#
# Project created by QtCreator 2016-03-15T02:54:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Morpion
TEMPLATE = app

CONFIG += c++14

SOURCES += main.cpp\
    morpion.cpp \
    fenetre.cpp \
    ia.cpp

HEADERS  += \
    morpion.h \
    fenetre.h \
    ia.h

FORMS    += mainwindow.ui
