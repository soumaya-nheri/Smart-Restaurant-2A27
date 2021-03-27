#include "commande_impl.h"

#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDate>
#include <QTableView>
Commande_Impl::Commande_Impl()
{
 this->plats = "";
    this->prixtotale = "0";
}

Commande_Impl::Commande_Impl(QString plats,QString prixtotale )
{
    this->plats = plats;
    this->prixtotale =prixtotale;

}



   bool Commande_Impl::ajouter(QString plats,QString prixtotale)
   {
       QSqlQuery qry;
       qry.prepare("INSERT INTO COMMANDE ( PLATS,PRIXTOTALE) "
                                       "VALUES (:PLATS,:PRIXTOTALE)");

           qry.bindValue(":PLATS",plats);
           qry.bindValue(":PRIXTOTALE",prixtotale);
           return qry.exec();
   }
   QSqlTableModel *Commande_Impl::afficher()
   {
      QSqlTableModel *mmodel = new QSqlTableModel();
       mmodel->setTable("COMMANDE");
      // mmodel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
      // mmodel->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
      // mmodel->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
       mmodel->select();
       return mmodel;

   }
    QSqlTableModel *Commande_Impl::supprimer ()
   {
       QSqlTableModel *mmodel = new QSqlTableModel();
        mmodel->setTable("COMMANDE");
        mmodel->select();
        return mmodel;

   }

    void Commande_Impl :: platsstatut(QTableView * table  )
    {
        QSqlQueryModel *model= new QSqlQueryModel();

        QSqlQuery *query=new QSqlQuery;
        query->prepare("select * from MENU where STATUT > 0;");


        query->exec();
        model->setQuery(*query);
        table->setModel(model);
        table->show();

    }
    void Commande_Impl::cleartable(QTableView * table)
    {
        QSqlQueryModel *model= new QSqlQueryModel();
        model->clear();
        table->setModel(model);
    }


