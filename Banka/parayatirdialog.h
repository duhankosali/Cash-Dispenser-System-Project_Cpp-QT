#ifndef PARAYATIRDIALOG_H
#define PARAYATIRDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QMainWindow>

#include <QTextEdit>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>




namespace Ui {
class parayatirDialog;
}

class parayatirDialog : public QDialog
{
    Q_OBJECT

public:
    explicit parayatirDialog(QWidget *parent = nullptr);
    ~parayatirDialog();

private:
    Ui::parayatirDialog *ui;
    // parayatirDialog *paraYatir;


private slots:

    void NumPressed(); // sayılar için oluşturulan fonksiyon, bu fonksiyonu MainWindow.cpp de doldurduk

    void on_buttonENTER_clicked();


    void on_pushButton_clicked();
};

#endif // PARAYATIRDIALOG_H
