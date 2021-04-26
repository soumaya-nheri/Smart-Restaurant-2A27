#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_reservation.h"
#include "gestion_table.h"
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
