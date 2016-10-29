QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += svg

TEMPLATE = app

include(paper_dna_helix.pri)

SOURCES += qtmain.cpp \
        qtdialog.cpp

HEADERS  += qtdialog.h

FORMS    += qtdialog.ui
