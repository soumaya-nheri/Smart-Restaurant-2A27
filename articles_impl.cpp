#include "articles_impl.h"

articles_impl::articles_impl()
{
this->nom = "";
 this->quantite = 0;

}

articles_impl::articles_impl(QString nom, int quantite)
{
this->nom = nom;
 this->quantite =quantite;

}


bool articles_impl::ajouter(QString nom, int quantite)
{
    QSqlQuery qry;
                qry.prepare("INSERT INTO ARTICLE ( NOM,QUANTITE) "
                                    "VALUES (:NOM,:QUANTITE)");


        qry.bindValue(":NOM",nom);
        qry.bindValue(":QUANTITE",quantite);
        return qry.exec();
}
QSqlTableModel *articles_impl::afficher()
{
   QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("ARTICLE");
    mmodel->select();
    return mmodel;

}
 QSqlTableModel *articles_impl::supprimer ()
{
    QSqlTableModel *mmodel = new QSqlTableModel();
     mmodel->setTable("ARTICLE");
     mmodel->select();
     return mmodel;

}


 void articles_impl :: recherche(QTableView * table ,QString nom )
 {
     QSqlQueryModel *model= new QSqlQueryModel();

     QSqlQuery *query=new QSqlQuery;
     query->prepare("select * from ARTICLE where NOM like '%"+nom+"%' ;");


     query->exec();
     model->setQuery(*query);
     table->setModel(model);
     table->show();

 }
 void articles_impl::cleartable(QTableView * table)
 {
     QSqlQueryModel *model= new QSqlQueryModel();
     model->clear();
     table->setModel(model);
 }

