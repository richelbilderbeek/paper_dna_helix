QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += svg

TEMPLATE = app

include(paper_dna_helix.pri)

SOURCES += qtmain.cpp \
        qtdialog.cpp

HEADERS  += qtdialog.h

FORMS    += qtdialog.ui

# C++14
CONFIG += c++14
QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -Wall -Wextra -Weffc++ -Werror -std=c++14
