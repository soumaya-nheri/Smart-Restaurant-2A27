#include "menu.h"

menu::menu(int id,QString nom ,QString prix)
{
    this->id=id;
    this->nom=nom;
    this->prix=prix;

}
bool menu::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);

    //prepare() prend la requete en parametre pour la preparer a l'execution

    query.prepare("insert into commande (id,nom,prix)" "values (:id, :nom, :prix)");

    //Creation des variables liées
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prix",prix);

    return query.exec(); //exec() envoie la requete pour l"executeur
}

QSqlQueryModel * menu::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from menu");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));

    return model;
}

bool menu::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("Delete from menu where ID=:id");
    query.bindValue(":id",res);
    return query.exec();
}
