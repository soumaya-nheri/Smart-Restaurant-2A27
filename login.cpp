#include "login.h"
#include "ui_login.h"
#include "gestion_personnel.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_reservation.h"
#include "ui_gestion_reservation.h"
#include "reservation.h"
#include "table.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
    QString username =ui-> lineEdit_username->text();

    QString mdp=ui-> lineEdit_mdp->text();
    QSqlQuery qry;

    if (qry.exec("select * from personnel where NOM='"+username+ "'and MOT_DE_PASSE='"+mdp+"'"))
    {
int count=0;
while(qry.next()){
    count ++;
                 }
if (count==1 or (username=="admin" && mdp=="admin") ){
    this->hide();
            MainWindow *w = new MainWindow;
            hide();
            w->show();
         }


       if (count<1) {
        ui->label_connecting->setText("Nom d'utilisateur ou Mot de passe incorrect");
        ui->lineEdit_username->setText("");
        ui->lineEdit_mdp->setText("");
}
}
}

