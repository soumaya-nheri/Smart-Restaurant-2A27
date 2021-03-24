#include "gestion_reservation.h"
#include "ui_gestion_reservation.h"

gestion_reservation::gestion_reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_reservation)
{
    ui->setupUi(this);
}

gestion_reservation::~gestion_reservation()
{
    delete ui;
}
