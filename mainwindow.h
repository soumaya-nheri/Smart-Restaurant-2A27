#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <personnel.h>
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



private:
    Ui::MainWindow *ui;
    Personnel P;
};

#endif // MAINWINDOW_H