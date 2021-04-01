#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <personnel.h>
#include <absence.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);



    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_supprimer_pb_clicked();

    void on_Ajouter_absence_clicked();

    void on_Modifier_absence_clicked();

    void on_Supprimer_absence_clicked();

private:
    Ui::MainWindow *ui;
    Personnel P;
    Absence A;
};

#endif // MAINWINDOW_H
