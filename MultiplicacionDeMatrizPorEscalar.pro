#-------------------------------------------------
#
# Project created by QtCreator 2015-11-04T15:38:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MultiplicacionDeMatrizPorEscalar
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    DoubleSpinBoxDelegate.cpp \
    IntroducirOdenMatrizDialog.cpp

HEADERS  += Widget.h \
    DoubleSpinBoxDelegate.h \
    IntroducirOdenMatrizDialog.h

FORMS    += Widget.ui \
    IntroducirOdenMatrizDialog.ui

QMAKE_CXXFLAGS += -std=gnu++14
