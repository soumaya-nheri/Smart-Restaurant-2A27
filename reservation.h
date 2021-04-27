#ifndef RESERVATION_H
#define RESERVATION_H
#include "gestion_reservation.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>

class reservation
{
public:
    reservation();

     reservation(int ID, QString NOM_CLIENT, QString NUM_TEL, QString TABLE_NUM, int NOMBRE_PERSONNES);
    reservation(QString NOM_CLIENT, QString NUM_TEL, QString TABLE_NUM, int NOMBRE_PERSONNES);
    bool ajouter();
    void afficher(Ui::Gestion_reservation *ui);
    bool Supprimer(Ui::Gestion_reservation *ui);
    bool modifier(Ui::Gestion_reservation *ui);
    void tables(Ui::Gestion_reservation *ui);
    void Recherche(Ui::Gestion_reservation *ui);
    int NOMBRE_TABLES();
    int NOMBRE_RESERVATION();
    void GRAPH(Ui::Gestion_reservation *ui);
    int getID();
    void setID(int &value);
    QString getNOM_CLIENT();
    void setNOM_CLIENT(QString &value);
    QString getTABLE_NUM();
    void setTABLE_NUM(QString &value);
    QString getNUM_TEL();
    void setNUM_TEL(QString &value);
    int getNOMBRE_PERSONNES();
    void setNOMBRE_PERSONNES(int &value);

private:
    QString TABLE_NUM,NOM_CLIENT;
    int ID,NOMBRE_PERSONNES;
    QString NUM_TEL;
};

#endif // RESERVATION_H
