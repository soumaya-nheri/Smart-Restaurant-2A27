#include "mainwindow.h"
#include "articles.h"
#include "fournisseur.h"
#include "categorie.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{ hide();
    articles *m = new articles();
    m->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    Fournisseur *m = new Fournisseur();
    m->show();
}

void MainWindow::on_pushButton_clicked()
{ hide();
    Categorie *m = new Categorie();
    m->show();

}
