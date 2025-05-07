#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Connect_clicked();
    void on_Quitter_clicked();
    void on_Payer_clicked();
    void on_Maj_clicked();
    void on_Disconnect_clicked();
    void on_Charger_clicked();
    void on_Select_carte_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
