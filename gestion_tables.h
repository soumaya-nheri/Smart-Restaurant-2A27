#ifndef GESTION_TABLES_H
#define GESTION_TABLES_H

#include <QDialog>

namespace Ui {
class gestion_tables;
}

class gestion_tables : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_tables(QWidget *parent = nullptr);
    ~gestion_tables();

private:
    Ui::gestion_tables *ui;
};

#endif // GESTION_TABLES_H
