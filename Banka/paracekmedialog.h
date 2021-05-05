#ifndef PARACEKMEDIALOG_H
#define PARACEKMEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QMainWindow>

#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>



namespace Ui {
class paracekmeDialog;
}

class paracekmeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit paracekmeDialog(QWidget *parent = nullptr);
    ~paracekmeDialog();

private slots:

    void NumPressed(); // sayılar için oluşturulan fonksiyon, bu fonksiyonu MainWindow.cpp de doldurduk

    void on_buttonENTER_clicked();

    void on_pushButton_clicked();

private:
    Ui::paracekmeDialog *ui;

};

#endif // PARACEKMEDIALOG_H
