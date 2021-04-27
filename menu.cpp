#include "menu.h"
#include "commande.h"
#include "ui_menu.h"
#include "menu_impl.h"
#include "commande_impl.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_reservation.h"
#include "ui_gestion_reservation.h"
#include "reservation.h"
#include "table.h"

#include<QIntValidator>
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    Menu_Impl cat ;
    Commande_Impl com ;
     ui->txt_Prix->setValidator(new QIntValidator(0,999999,this));
  //  com.cleartable(ui->tableView2);
    com.platsstatut(ui->tableView2);
  //  ui->tableView2->setModel(com.afficher());
    ui->tableView->setModel(cat.afficher());
    ui->tableView3->setModel(com.affichercommande());
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_Ajouter_clicked()
{ float prixcheck;
    QString nom = ui->txt_Nom->text();
    QString prix = ui->txt_Prix->text();

    if(nom == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                                       QObject::tr("Case obligatoire\nverifier le nom\n"), QMessageBox::Cancel);
    }
    if(prix == "")
    {
        QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                                       QObject::tr("Case obligatoire\nverifier le prix\n"), QMessageBox::Cancel);
    }


    else
    {
        Menu_Impl cat ;
        cat.ajouter(nom,prix);
           ui->tableView->setModel(cat.afficher());
    }


}

void Menu::on_Supprimer_clicked()
{
    Menu_Impl cat ;
    cat.supprimer()->removeRow(ui->tableView->currentIndex().row());
      ui->tableView->setModel(cat.afficher());

}

void Menu::on_txt_Search_textChanged(const QString &arg1)
{
    Menu_Impl c;

    c.cleartable(ui->tableView);
QString nom = ui->txt_Search->text();
c.recherche(ui->tableView,nom);
if (ui->txt_Search->text().isEmpty())
{
    ui->tableView->setModel(c.afficher());
}
}
void Menu::on_Actualiser_clicked()
{
    Commande_Impl com ;
    Menu_Impl men;
   com.cleartable(ui->tableView2);
    com.platsstatut(ui->tableView2);
    com.cleartable(ui->tableView3);
     ui->tableView3->setModel(com.affichercommande());
    men.cleartable(ui->tableView);
      ui->tableView->setModel(men.afficher());
}


void Menu::on_Trier_clicked()
{
    Menu_Impl men;
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;

    query->prepare("select * from MENU ORDER BY NOM ASC ;");
    query->exec();
    model->setQuery(*query);
     men.cleartable(ui->tableView);
    ui->tableView->setModel(model);
    ui->tableView->show();


}


void Menu::on_Retour_clicked()
{
    MainWindow *w = new MainWindow;
    hide();
    w->show();
}
