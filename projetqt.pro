QT       += core gui
QT       += sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console

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
    fournisseur_impl.cpp \
    main.cpp \
    mainwindow.cpp \
    notifications.cpp \
    statistique.cpp

HEADERS += \
    articles.h \
    articles_impl.h \
    categorie.h \
    categorie_impl.h \
    connexion.h \
    fournisseur.h \
    fournisseur_impl.h \
    mainwindow.h \
    notifications.h \
    statistique.h

FORMS += \
    articles.ui \
    categorie.ui \
    fournisseur.ui \
    mainwindow.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressource.qrc
