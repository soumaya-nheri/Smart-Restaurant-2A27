#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore/qglobal.h>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_reservation.h"
#include "ui_gestion_reservation.h"
#include "reservation.h"
#include "table.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QPrinter>
#include<QPrintDialog>
#include<QFileSystemModel>
#include<QDebug>
#include<QDateTime>

Gestion_reservation::Gestion_reservation(QWidget *parent) :
QWidget(parent),
ui(new Ui::Gestion_reservation)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(myfunction()));
    timer->start(1000);
ui->setupUi(this);
reservation R;
R.tables(ui);
R.afficher(ui);
R.GRAPH(ui);
if(R.NOMBRE_TABLES()==0)
{ui->ajouter->setDisabled(true);
ui->table_msg->setText("pas de tables disponibles");
}
else
{
ui->ajouter->setDisabled(false);
ui->table_msg->setText("");
}
notifyicon=new QSystemTrayIcon(this);
notifyicon->setIcon(QIcon(":/images/Notification.jpg"));
notifyicon->setVisible(true);
ui->modifier->setDisabled(true);
ui->tabWidget->setCurrentIndex(1);
}

Gestion_reservation::~Gestion_reservation()
{
delete ui;
}

void Gestion_reservation::on_ajouter_clicked()
{
reservation R;
table T ;
QRegExp regex1 ("[a-z]$");
QRegExp regex2 ("^[a-z]");
QString msg_nom ="nom  invalide";
QString msg_nombre ="nombre invalide";
QString msg_tel ="numero telephone invalide";
QString msg_vide="";

QString table= ui->tables->currentText();
QString nom= ui->nom->text();
QString tel = ui->telephone->text();
int nombre = ui->nombre->text().toInt();
int ok=0;


if ((!nom.contains(regex1))||(!nom.contains(regex2)))
{
ui->nom_msg->setStyleSheet("QLabel { color: red;}");
ui->nom_msg->setText(msg_nom);

ok++;
}
else { ui->nom_msg->setStyleSheet("QLabel { color: black;}");

ui->nom_msg->setText(msg_vide);
}


if( ui->telephone->text().length()!=8)
{
ui->telephone_msg->setStyleSheet("QLabel { color: red;}");
ui->telephone_msg->setText(msg_tel);

ok++;
}
else {
ui->telephone_msg->setStyleSheet("QLabel { color: black;}");
ui->telephone_msg->setText(msg_vide);
}

if( nombre<=0 )
{
ui->nombre_places_msg->setStyleSheet("QLabel { color: red;}");
ui->nombre_places_msg->setText(msg_nombre);

ok++;
}
else {
ui->nombre_places_msg->setStyleSheet("QLabel { color: black;}");
ui->nombre_places_msg->setText(msg_vide);
}
if (ok==0)
{
reservation R(nom,tel,table,nombre);
if (R.ajouter())
{
ui->nom->setStyleSheet("QLineEdit { color: green;}");
ui->telephone->setStyleSheet("QLineEdit { color: green;}");
ui->nombre_places_msg->setStyleSheet("QLineEdit { color: green;}");
notifyicon->show();
notifyicon->showMessage("Success ","Votre reservation a été bien ajouté ",QSystemTrayIcon::Information,2000);
R.afficher(ui);
ui->tabWidget->setCurrentIndex(1);
}
else {
{QMessageBox ::critical(this,"","erreur d'ajout") ;

}
}
}

else
{QMessageBox ::information(this,"","erreur d'ajout  ") ;}
}




void Gestion_reservation::on_supprimer_clicked()
{
reservation R;
if(R.Supprimer(ui))
{
QMessageBox ::information(this,"","Reservation Supprimé")  ;

R.afficher(ui);

}
}

void Gestion_reservation::on_tableView_doubleClicked()
{

ui->ID->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
ui->nom_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
ui->tables2->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString());
ui->telephone2->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
ui->nombre2->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
ui->tabWidget->setCurrentIndex(2);
ui->modifier->setDisabled(false);
}

void Gestion_reservation::on_reset_3_clicked()
{ui->ID->clear();
ui->nom_2->clear();
ui->tables2->clear();
ui->nombre2->clear();
ui->tabWidget->setCurrentIndex(1);
ui->modifier->setDisabled(true);
}
void Gestion_reservation::on_recherche_textChanged(const QString &arg1)
{
QString result ;
reservation R;
R.Recherche(ui);
}
void Gestion_reservation::on_retour_clicked()
{
MainWindow *w = new MainWindow;
hide();
w->show();

}
void Gestion_reservation::on_modifier_clicked()
{
reservation R;
table T ;
QRegExp regex1 ("[a-z]$");
QRegExp regex2 ("^[a-z]");
QString msg_nom ="nom  invalide";
QString msg_nombre ="nombre invalide";
QString msg_tel ="numero telephone invalide";
QString msg_vide="";
QString table= ui->tables2->currentText();
QString nom= ui->nom_2->text();
int ID= ui->ID->text().toInt();
QString tel = ui->telephone2->text();
int nombre = ui->nombre2->text().toInt();
int ok=0;


if ((!nom.contains(regex1))||(!nom.contains(regex2)))
{
ui->nom_msg->setStyleSheet("QLabel { color: red;}");
ui->nom_msg->setText(msg_nom);

ok++;
}
else { ui->nom_msg->setStyleSheet("QLabel { color: black;}");

ui->nom_msg->setText(msg_vide);
}


if( tel.length()!=8)
{
ui->telephone_msg->setStyleSheet("QLabel { color: red;}");
ui->telephone_msg->setText(msg_tel);

ok++;
}
else {
ui->telephone_msg->setStyleSheet("QLabel { color: black;}");
ui->telephone_msg->setText(msg_vide);
}

if( nombre<=0 )
{
ui->nombre_places_msg->setStyleSheet("QLabel { color: red;}");
ui->nombre_places_msg->setText(msg_nombre);

ok++;
}
else {
ui->nombre_places_msg->setStyleSheet("QLabel { color: black;}");
ui->nombre_places_msg->setText(msg_vide);
}
if (ok==0)
{
reservation R(ID,nom,tel,table,nombre);

if (R.modifier(ui))
{
ui->nom_2->setStyleSheet("QLineEdit { color: green;}");
ui->nombre2->setStyleSheet("QLineEdit { color: green;}");
ui->telephone2->setStyleSheet("QLineEdit { color: green;}");
{QMessageBox ::information(this,""," reservation modifié  ") ;}

R.afficher(ui);
ui->tabWidget->setCurrentIndex(1);
ui->ID->clear();
ui->nom_2->clear();
ui->tables2->clear();
ui->nombre2->clear();
ui->telephone2->clear();
ui->modifier->setDisabled(true);
}
else {
{QMessageBox ::critical(this,"","erreur de modification 1") ;

}
}
}

else
{QMessageBox ::information(this,"","erreur de modification 2 ") ;}
}

void Gestion_reservation::on_retour_2_clicked()
{
    MainWindow *w = new MainWindow;
    hide();
    w->show();

}

void Gestion_reservation::on_retour_3_clicked()
{
    MainWindow *w = new MainWindow;
    hide();
    w->show();

}

void Gestion_reservation::on_pushButton_6_clicked()
{
    QPrinter printer;
     printer.setPrinterName("imprimer");
     QPrintDialog dialog(&printer, this);
     if (dialog.exec() == QDialog::Rejected) return;
     ui->tabWidget->render(&printer);
}

void Gestion_reservation::on_pushButton_5_clicked()
{
    QPrinter printer;
     printer.setPrinterName("imprimer");
     QPrintDialog dialog(&printer, this);
     if (dialog.exec() == QDialog::Rejected) return;
     ui->tabWidget->render(&printer);
}

void Gestion_reservation::on_pushButton_4_clicked()
{
    QPrinter printer;
     printer.setPrinterName("imprimer");
     QPrintDialog dialog(&printer, this);
     if (dialog.exec() == QDialog::Rejected) return;
     ui->tabWidget->render(&printer);
}

void Gestion_reservation::on_pushButton_3_clicked()
{
    QPrinter printer;
     printer.setPrinterName("imprimer");
     QPrintDialog dialog(&printer, this);
     if (dialog.exec() == QDialog::Rejected) return;
     ui->tabWidget->render(&printer);
}

void Gestion_reservation::on_retour_4_clicked()
{

    MainWindow *w = new MainWindow;
    hide();
    w->show();
}
void Gestion_reservation::myfunction()
{
QTime time = QTime::currentTime();
QString time_text = time.toString("hh : mm : ss");
if ((time.second() % 2) == 0){
    time_text[3] = ' ';
    time_text[8] = ' ';
}
ui->label_time->setText(time_text);

}

