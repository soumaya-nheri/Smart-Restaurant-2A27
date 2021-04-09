#include "menu.h"
#include "ui_menu.h"
#include "menu_impl.h"
#include "commande_impl.h"
#include <QMessageBox>


void Menu::on_Supprimer2_clicked()
{
    Commande_Impl cat ;
    cat.supprimer()->removeRow(ui->tableView3->currentIndex().row());
      ui->tableView3->setModel(cat.affichercommande());

}
void Menu::on_Supprimer3_clicked()
{
    Commande_Impl cat ;
    QSqlQuery qry;
    qry.prepare("DELETE FROM COMMANDE");

       qry.exec();
      ui->tableView3->setModel(cat.affichercommande());

}


void Menu::on_Valider_clicked()
{
    QString nom,prix,plats,prixtotale;
    Commande_Impl com ;

    QSqlQuery *query=new QSqlQuery;
    query->prepare("INSERT INTO COMMANDE (PLATS,PRIX,QUANTITE) select NOM,PRIX,QUANTITE from MENU WHERE QUANTITE > 0 ;");
    query->exec();
    query->prepare("update MENU SET QUANTITE = 0 ;");
    query->exec();

   // query->prepare("insert into COMMANDE (PLATS,PRIXTOTALE) select NOM,PRIX from MENU where QUANTITE > 0;");
   /*   query->bindValue(":NOM",nom);
    query->bindValue(":PRIX",prix);
    query->exec();
    plats=nom;
    prixtotale=prix;
    com.ajouter(plats,prixtotale);*/


  /*
  *
  *
  *  QString plats = ui->txt_Nom->text();
     QString prixtotale = ui->txt_Nom->text();
  if(plats == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                                       QObject::tr("Case obligatoire\nverifier le nom\n"), QMessageBox::Cancel);
    }
    else
    {
        Commande_Impl cat ;
        cat.ajouter(plats,prixtotale);
           ui->tableView->setModel(cat.afficher());
    }
*/

}

void Menu::on_imprimer_clicked()
{    Commande_Impl cat ;
  cat.telecharger();

    QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);



}



