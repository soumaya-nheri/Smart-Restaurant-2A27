#ifndef RESERVATION_H
#define RESERVATION_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class Reservation
{
    QString nom ;
    int tel,id;
public:
    Reservation();
    Reservation( int,int,QString);
    //getters
    QString getNom() {return nom;}
    int getID(){return id;}
    int getTel(){return tel;}
    //setters
    void setNom(QString n){nom=n;}
    void setID(int id){this-> id=id;}
    void setTel(int tel){this-> tel=tel;}
bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(int);


};

#endif // RESERVATION_H
