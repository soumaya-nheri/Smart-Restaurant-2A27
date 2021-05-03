#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_reservation.h"
#include "gestion_personnel.h"
#include "gestion_livraison.h"
#include "gestion_table.h"
#include "articles.h"
#include "fournisseur.h"
#include "categorie.h"
#include "login.h"
#include "menu.h"
#include "commande.h"
#include "menu_impl.h"
#include "commande_impl.h"
#include "stat_commande.h"
#include "fournisseur.h"
#include "fournisseur_impl.h"
#include "categorie_impl.h"
#include "categorie.h"
#include "categorie_impl.h"
#include "articles.h"
#include "articles_impl.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QPrinter>
#include<QPrintDialog>
#include<QFileSystemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //menu
    Menu_Impl men ;
    Commande_Impl com ;
    ui->txt_Prix_menu->setValidator(new QIntValidator(0,999999,this));
    com.platsstatut(ui->tableView2_menu);
    ui->tableView_menu->setModel(men.afficher());
    ui->tableView3_commande->setModel(com.affichercommande());
    //article
    articles_impl art;
    ui->tableView_article->setModel(art.afficher());
    art.verifier();
    //categorie
    Categorie_Impl cat ;
    ui->tableView_categorie->setModel(cat.afficher());
    //fournisseur
    Categorie_Impl c;
     ui->comboBox_fournisseur->addItems(c.getNames());
     //personnel
     ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
     ui->le_tel->setValidator( new QIntValidator(0, 99999999, this));
     ui->tab_personnel->setModel(P.afficher());
     ui->tab_absence->setModel((A.afficher()));
    ui->comboBox_supp->setModel(P.afficher_CIN());
    ui->comboBox_nom->setModel(P.afficher_NOM());
    ui->comboBox_id3->setModel(A.afficher_ID());
    mysystem = new QSystemTrayIcon(this);
    mysystem->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_gestio_tables_clicked()
{
    Gestion_table *w = new Gestion_table;
   hide();
   w->show();
}



void MainWindow::on_pushButton_acceuil_clicked()
{
    Gestion_reservation *w = new Gestion_reservation;
   hide();
   w->show();
}

void MainWindow::on_menu_clicked()
{
 /*   Menu *w = new Menu;
   hide();
   w->show();*/
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_gestion_personnel_clicked()
{

    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_gestion_livraison_clicked()
{
  ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_gestion_article_clicked()
{
   /* hide();
       articles *m = new articles();
       m->show();*/
       ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_gestion_fournisseur_clicked()
{
   /* hide();
    Fournisseur *m = new Fournisseur();
    m->show();*/
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_gestion_categorie_clicked()
{
   /* hide();
        Categorie *m = new Categorie();
        m->show();*/
         ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}
void MainWindow::on_pb_ajouter_clicked()
{
    QString cin=ui->le_id->text();
    QString tel=ui->le_tel->text();
    QString service=ui->le_service->currentText();
    QString nom=ui->le_nom->text();
    QString mail=ui->le_prenom->text();
    QString mot_de_passe=ui->le_mdp->text();
    Personnel P(cin,tel,service,nom,mail,mot_de_passe);

    if(nom == ""||service==""||mail==""||mot_de_passe=="")
        {
            QMessageBox::critical(nullptr, QObject::tr("Problem "),
                                           QObject::tr("Champ vide !\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
        }
   else{ bool test=P.ajouter();
if(test)
{ QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("Ajout effectué"), QMessageBox::Cancel);
    ui->tab_personnel->setModel(P.afficher());
    ui->comboBox_supp->setModel(P.afficher_CIN());
    ui->comboBox_nom->setModel(P.afficher_NOM());
    ui->le_id->setText("");
    ui->le_tel->setText("");
    ui->le_nom->setText("");
    ui->le_prenom->setText("");
    ui->le_mdp->setText("");
    mysystem->show();
    mysystem->showMessage(tr("notification"),tr("Ajout effectué avec succés"));

}
else
    QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                          QObject::tr("Ajout non effectué"), QMessageBox::Cancel);
}

}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    Personnel P;

    P.cleartable(ui->tab_personnel);
QString nom = ui->lineEdit->text();
P.recherche(ui->tab_personnel,nom);
if (ui->lineEdit->text().isEmpty())
{
    ui->tab_personnel->setModel(P.afficher());
}
}

void MainWindow::on_supprimer_pb_clicked()
{

        bool test=P.supprimer(ui->comboBox_supp->currentText());
        if(test)
        {ui->tab_personnel->setModel(P.afficher());
                QMessageBox::information(nullptr,QObject::tr("OK"),
                                         QObject::tr("suppression succful .\n"),
                        QMessageBox::Cancel);
            }

            else
                QMessageBox::critical(nullptr,QObject::tr("ERROR"),
                                        QObject::tr("click cancel to exist"),
                                        QMessageBox::Cancel);
        ui->comboBox_supp->setModel(P.afficher_CIN());
        ui->comboBox_nom->setModel(P.afficher_NOM());
        mysystem->show();
        mysystem->showMessage(tr("notification"),tr("suppression effectuée avec succés"));

}

void MainWindow::on_Ajouter_absence_clicked()
{
    Absence A(ui->id_absence->text().toInt(),ui->comboBox_nom->currentText(),ui->comboBox_motif->currentText(),ui->date->text());
   bool test= A.ajouterAB();
   if(test)
   { QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("Ajout effectué"), QMessageBox::Cancel);
       ui->tab_absence->setModel(A.afficher());
       ui->comboBox_id3->setModel(A.afficher_ID());
       //ui->id_absence->setText("");
       mysystem->show();
       mysystem->showMessage(tr("notification"),tr("Ajout effectué avec succés"));
   }
   else
       QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                             QObject::tr("Ajout non effectué"), QMessageBox::Cancel);
   }


void MainWindow::on_Supprimer_absence_clicked()
{
    bool test=A.supprimerAB(ui->comboBox_id3->currentText().toInt());
    if(test)
    {ui->tab_absence->setModel(A.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
              ui->comboBox_id3->setModel(A.afficher_ID());
              mysystem->show();
              mysystem->showMessage(tr("notification"),tr("suppression effectuée avec succés"));
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("ERROR"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);

}

void MainWindow::on_pdf_absence_clicked()
{
   A.telechargerPDF();

    QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);



}

void MainWindow::on_pushButton_6_clicked()
{

    QPrinter printer;
     printer.setPrinterName("imprimer");
     QPrintDialog dialog(&printer, this);
     if (dialog.exec() == QDialog::Rejected) return;
     ui->tab_personnel->render(&printer);

}

void MainWindow::on_triernom_clicked()
{
    ui->tab_absence->setModel(A.triernom());
}

void MainWindow::on_triermotif_clicked()
{
    ui->tab_absence->setModel(A.triermotif());
}

void MainWindow::on_trierdate_clicked()
{
    ui->tab_absence->setModel(A.trierdate());
}

void MainWindow::on_Retour_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Retour_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}
//livraison
void MainWindow::on_ajouter_livreur_clicked()
{
    QString cin=ui->cin->text();
    QString nom=ui->le_nom_2->text();
    QString tel=ui->le_tel_2->text();
    QString disponibilite=ui->le_disponibilite->text();


        livreur L(cin,nom,tel,disponibilite);
        if(nom == "")
            {
                QMessageBox::critical(nullptr, QObject::tr("Problem "),
                                               QObject::tr("Champ vide !\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
            }
       else{ bool test=L.ajouter();
    if(test)
    { QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Ajout effectué"), QMessageBox::Cancel);
        ui->tab_livreur->setModel(L.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué"), QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_12_clicked()
{
    livreur l;
            QString x=ui->suppline->text();
            bool test=l.supprimer(x);
            QMessageBox msgBox;

            if(test)
               {
                msgBox.setText("Suppression avec succes.");
                ui->tab_livreur->setModel(L.afficher());
                }
            else
               { msgBox.setText("Echec de suppression");
                msgBox.exec();}
}

void MainWindow::on_pushButton_11_clicked()
{
    QString cin=ui->cin_modifier->text();
    QString disponibilite= ui->disponibilite_modifier->text();
    QString nom= ui->nom_modifier->text();
    QString tel= ui->tel_modifier->text();


         livreur L(cin,nom,tel,disponibilite);
         bool test=L.modifier();
         QMessageBox msgBox;
        if(test)
          {  msgBox.setText("Modifier avec succes.");
             ui->tab_livreur->setModel(L.afficher());
          }
        else
           { msgBox.setText("Echec de modification");
            msgBox.exec();}
}

void MainWindow::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    livreur l;

        l.cleartable(ui->tab_livreur);
    QString nom = ui->lineEdit_recherche->text();
    l.recherche(ui->tab_livreur,nom);
    if (ui->lineEdit_recherche->text().isEmpty())
    {
        ui->tab_livreur->setModel(l.afficher());
    }
}

void MainWindow::on_pushButton_5_clicked()
{QString commande=ui->numcommande->text();
    QString nom=ui->nomclient->text();
    QString tel=ui->tel->text();
    QString region=ui->region->text();
    QString ville=ui->ville->text();
    QString adresse=ui->adresse->text();



        livraison L(commande,nom,tel,region,ville,adresse);
        if(nom == "")
            {
                QMessageBox::critical(nullptr, QObject::tr("Problem "),
                                               QObject::tr("Champ vide !\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
            }
       else{ bool test=L.ajouter();
    if(test)
    { QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Ajout effectué"), QMessageBox::Cancel);
        ui->tab_livraison->setModel(L.afficher());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué"), QMessageBox::Cancel);
}

}

void MainWindow::on_pushButton_8_clicked()
{QString commande=ui->numcommande1->text();
    QString region= ui->region1->text();
    QString nom= ui->nomclient1->text();
    QString tel= ui->tel1->text();
    QString ville= ui->ville1->text();
    QString adresse= ui->adresse1->text();



         livraison L(commande,nom,tel,region,ville,adresse);
         bool test=L.modifier();
         QMessageBox msgBox;
        if(test)
          {  msgBox.setText("Modifier avec succes.");
             ui->tab_livraison->setModel(L.afficher());
          }
        else
           { msgBox.setText("Echec de modification");
            msgBox.exec();}

}



void MainWindow::on_pushButton_7_clicked()
{
    livraison liv;
            QString x=ui->lineEdit_7->text();
            bool test=liv.supprimer(x);
            QMessageBox msgBox;

            if(test)
               {
                msgBox.setText("Suppression avec succes.");
                ui->tab_livraison->setModel(liv.afficher());
                }
            else
               { msgBox.setText("Echec de suppression");
                msgBox.exec();}
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this, "Alerte", "Message envoyé au livreur");

}







void MainWindow::on_Retour_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Retour_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

