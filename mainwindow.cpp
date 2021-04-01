#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include"absence.h"
#include <QMessageBox>
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_tel->setValidator( new QIntValidator(0, 99999999, this));
    ui->tab_personnel->setModel(P.afficher());
    ui->tab_absence->setModel((A.afficher_tab()));
   ui->comboBox_supp->setModel(P.afficher_CIN());
   ui->comboBox_modifier->setModel(P.afficher_CIN());
   ui->comboBox_nom->setModel(P.afficher_NOM());
   ui->comboBox_nom2->setModel(P.afficher_NOM());
   ui->comboBox_id3->setModel(A.afficher_ID());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->le_id->text().toInt();
    int tel=ui->le_tel->text().toInt();
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
}
else
    QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                          QObject::tr("Ajout non effectué"), QMessageBox::Cancel);
}
ui->comboBox_supp->setModel(P.afficher_CIN());
ui->comboBox_modifier->setModel(P.afficher_CIN());
ui->comboBox_nom->setModel(P.afficher_NOM());
ui->comboBox_nom2->setModel(P.afficher_NOM());


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


void MainWindow::on_pushButton_clicked()
{
    /*bool    test=P.modifier(ui->comboBox_modifier->currentText().toInt(),ui->tel2->text().toInt(),ui->nom2->text(),ui->mail2->text(),ui->service2->text(),ui->mdp2->text()) ;
          if (test)
          {
                ui->tab_personnel->setModel(P.afficher());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}*/
        int cin=ui->comboBox_modifier->currentText().toInt();
        QString nom=ui->nom2->text();
        QString service=ui->service2->text();
        QString mot_de_passe=ui->mdp2->text();
        QString mail=ui->mail2->text();
        int tel=ui->tel2->text().toInt();

                      Personnel P(cin,tel, nom,service, mot_de_passe, mail);

             bool test = P.modifier( cin,tel, nom,service, mot_de_passe, mail);


             if(test)

             {
                  ui->tab_personnel->setModel(P.afficher());
                 QMessageBox::information(nullptr, QObject::tr("update "),
                             QObject::tr("personnel modifie\n"
             "Click Cancel to exit."), QMessageBox::Cancel);}
             else
                 QMessageBox::critical(nullptr, QObject::tr("update "),
                             QObject::tr("personnel non modifie\n"
             "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_pb_clicked()
{

        bool test=P.supprimer(ui->comboBox_supp->currentText().toInt());
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
        ui->comboBox_modifier->setModel(P.afficher_CIN());
        ui->comboBox_supp->setModel(P.afficher_CIN());
        ui->comboBox_nom->setModel(P.afficher_NOM());
        ui->comboBox_nom2->setModel(P.afficher_NOM());


}

void MainWindow::on_Ajouter_absence_clicked()
{
    Absence A(ui->id_absence->text().toInt(),ui->comboBox_nom->currentText(),ui->comboBox_motif->currentText(),ui->date->text());
   bool test= A.ajouterAB();
   if(test)
   { QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("Ajout effectué"), QMessageBox::Cancel);
       ui->tab_absence->setModel(A.afficher_tab());
       ui->comboBox_id3->setModel(A.afficher_ID());
        //ui->comboBox_nom2->setModel(P.afficher_NOM());
         //ui->comboBox_4->setModel(co.afficheroncomboc());
   }
   else
       QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                             QObject::tr("Ajout non effectué"), QMessageBox::Cancel);
   }




/*void MainWindow::on_Modifier_absence_clicked()
{
    bool    test=A.modifierAB(ui->comboBox_nom2->currentText(),ui->comboBox_motif2->currentText(),ui->date2->text()) ;
          if (test)
          {
                ui->tab_absence->setModel(A.afficher_tab());

              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);
          }
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}*/


void MainWindow::on_Supprimer_absence_clicked()
{
    bool test=A.supprimerAB(ui->comboBox_id3->currentText().toInt());
    if(test)
    {ui->tab_absence->setModel(A.afficher_tab());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
              ui->comboBox_id3->setModel(A.afficher_ID());
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("ERROR"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
   A.telechargerPDF();

    QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);



}

