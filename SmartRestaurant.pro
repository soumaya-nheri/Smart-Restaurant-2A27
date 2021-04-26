#-------------------------------------------------
#
# Project created by QtCreator 2021-03-23T07:21:34
#
#-------------------------------------------------
QT       += core gui network  printsupport
QT       +=sql
QT += widgets multimedia serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartRestaurant
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    table.cpp \
    reservation.cpp \
    connexion.cpp \
    gestion_reservation.cpp \
    gestion_table.cpp \
    qcustomplot.cpp

HEADERS += \
        mainwindow.h \
    table.h \
    reservation.h \
    connexion.h \
    gestion_reservation.h \
    gestion_table.h \
    qcustomplot.h

FORMS += \
        mainwindow.ui \
    gestion_reservation.ui \
    gestion_table.ui

RESOURCES += \
    images.qrc
