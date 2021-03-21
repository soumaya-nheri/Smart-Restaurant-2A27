#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include <QMessageBox>
#include <QIntValidator>
#include <supprimer.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_tel->setValidator( new QIntValidator(0, 99999999, this));
    ui->tab_personnel->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->le_id->text().toInt();
    int tel=ui->le_tel->text().toInt();
    QString service=ui->le_service->text();
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

}


void MainWindow::on_pushButton_2_clicked()
{
    supprimer supp;
    supp.setModal(true);
    supp.exec();
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



