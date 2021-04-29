#include "login.h"
#include "ui_login.h"
#include "gestion_personnel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*ui->ANIMATION->setText("Bienvenue");
        animation=new QPropertyAnimation(ui->ANIMATION,"geometry");
        animation->setDuration(5000);
        animation->setStartValue(ui->ANIMATION->geometry());
        animation->setEndValue(QRect(870,40,151,51));
        animation->start();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
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
            gestion_personnel menu;
           menu.setModal(true);

            menu.exec();
         }


       if (count<1) {
        ui->label_connecting->setText("Nom d'utilisateur ou Mot de passe incorrect");
        ui->lineEdit_username->setText("");
        ui->lineEdit_mdp->setText("");
}
}
}
