#ifndef GESTION_RESERVATION_H
#define GESTION_RESERVATION_H

#include <QDialog>

namespace Ui {
class gestion_reservation;
}

class gestion_reservation : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_reservation(QWidget *parent = nullptr);
    ~gestion_reservation();

private:
    Ui::gestion_reservation *ui;
};

#endif // GESTION_RESERVATION_H
