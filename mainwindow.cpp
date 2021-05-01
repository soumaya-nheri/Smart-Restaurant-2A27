#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_reservation.h"
#include "gestion_personnel.h"
#include "gestion_livraison.h"
#include "gestion_table.h"
#include "menu.h"
#include "articles.h"
#include "fournisseur.h"
#include "categorie.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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



void MainWindow::on_pushButton_2_clicked()
{
    Gestion_reservation *w = new Gestion_reservation;
   hide();
   w->show();
}

void MainWindow::on_menu_clicked()
{
    Menu *w = new Menu;
   hide();
   w->show();
}

void MainWindow::on_gestion_personnel_clicked()
{
    gestion_personnel *w = new gestion_personnel;
   hide();
   w->show();
}

void MainWindow::on_gestion_livraison_clicked()
{
    gestion_livraison *w = new gestion_livraison;
   hide();
   w->show();
}

void MainWindow::on_gestion_article_clicked()
{
    hide();
       articles *m = new articles();
       m->show();
}

void MainWindow::on_gestion_fournisseur_clicked()
{
    hide();
    Fournisseur *m = new Fournisseur();
    m->show();
}

void MainWindow::on_gestion_categorie_clicked()
{
    hide();
        Categorie *m = new Categorie();
        m->show();
}
