#-------------------------------------------------
#
# Project created by QtCreator 2015-08-24T23:56:14
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_owniteratortest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_owniteratortest.cpp \
    owncontainer.cpp \
    owncontainerbbi.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    owncontainer.h \
    owniterator.h \
    owncontainerbbi.h \
    owniteratorbb.h

QMAKE_CXXFLAGS += --std=c++11

INCLUDEPATH += $$(BOOST)
