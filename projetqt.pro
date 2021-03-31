QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    articles.cpp \
    articles_impl.cpp \
    categorie.cpp \
    categorie_impl.cpp \
    connexion.cpp \
    fournisseur.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    articles.h \
    articles_impl.h \
    categorie.h \
    categorie_impl.h \
    connexion.h \
    fournisseur.h \
    mainwindow.h

FORMS += \
    articles.ui \
    categorie.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
