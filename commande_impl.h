#ifndef COMMANDE_IMPL_H
#define COMMANDE_IMPL_H
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>
#include <QTableView>
class Commande_Impl
{

   QString plats ;
   QString prixtotale;
   int statut;
public:
   //Constructeurs
      Commande_Impl();
      Commande_Impl(QString,QString);

   //Getters
      QString getPlats() {return plats;}
      QString getPrix(){return prixtotale;}

   //setters
      void setPlats(QString plats){this->plats=plats;}
       void setPrix(QString p){this->prixtotale=p;}
      bool ajouter(QString,QString);
      QSqlTableModel *supprimer();
      QSqlTableModel* afficher();
      void cleartable(QTableView * table);
      void platsstatut(QTableView * tabl);
};
#endif // COMMANDE_IMPL_H
