#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMessageBox>

#include <menudialog.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int bakiye=0;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_10_clicked();

    void on_buttonENTER_clicked();

    void NumPressed(); // sayılar için oluşturulan fonksiyon, bu fonksiyonu MainWindow.cpp de doldurduk



private:
    Ui::MainWindow *ui;
    MainWindow *mainWindow;
    MenuDialog *menuDialog;
};
#endif // MAINWINDOW_H
