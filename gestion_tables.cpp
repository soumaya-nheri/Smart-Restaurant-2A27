#include "gestion_tables.h"
#include "ui_gestion_tables.h"

gestion_tables::gestion_tables(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_tables)
{
    ui->setupUi(this);
}

gestion_tables::~gestion_tables()
{
    delete ui;
}
