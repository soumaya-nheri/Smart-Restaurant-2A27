QT       += core gui sql
QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    absence.cpp \
    connection.cpp \
    gestion_personnel.cpp \
    login.cpp \
    main.cpp \
    personnel.cpp

HEADERS += \
    absence.h \
    connection.h \
    gestion_personnel.h \
    login.h \
    personnel.h

FORMS += \
    gestion_personnel.ui \
    login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
