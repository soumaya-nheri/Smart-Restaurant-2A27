#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
    ui->tab_etudiant->setModel(P.afficher());
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
bool test=P.ajouter();
if(test)
{ QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("Ajout effectué"), QMessageBox::Cancel);
    ui->tab_etudiant->setModel(P.afficher());
}
else
    QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                          QObject::tr("Ajout non effectué"), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
    Personnel P1; P1.setcin(ui->le_id_supp->text().toInt());
    bool test=P1.supprimer(P1.getcin());

    QMessageBox msgBox;
    if(test)
    {
    msgBox.setText("Suppression avec succes.");
    ui->tab_etudiant->setModel(P.afficher());
    }
    else
    msgBox.setText("Echec de suppression");
    msgBox.exec();
}

