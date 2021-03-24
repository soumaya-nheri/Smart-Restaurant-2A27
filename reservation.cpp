#include "reservation.h"

Reservation::Reservation(int tel,int id,QString nom)

{

    this ->id=id;
    this ->tel=tel;
    this ->nom=nom;

}
bool Reservation::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("insert into etudiants(id,nom,tel)"" values(:id,:nom,:tel)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
      query.bindValue(":tel",tel);
    return query.exec();
}

QSqlQueryModel * Reservation::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("select * from article");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("tel"));

        return model;
}
bool Reservation::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("Delete from reservation where ID=:id");
    query.bindValue(":id",res);
      return query.exec();
}
