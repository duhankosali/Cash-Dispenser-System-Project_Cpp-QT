#ifndef MENUDIALOG_H
#define MENUDIALOG_H
#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>

#include <paracekmedialog.h>
#include <parayatirdialog.h>
#include <bakiyesorgulamadialog.h>
namespace Ui {
class MenuDialog;
}

class MenuDialog : public QDialog
{
    Q_OBJECT

public:

    explicit MenuDialog(QWidget *parent = nullptr);
    ~MenuDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MenuDialog *ui;
    MenuDialog *menuDialog;
    paracekmeDialog *paracekmedialog;
    parayatirDialog *parayatirdialog;
    bakiyesorgulamaDialog *bakiyesorgulamadialog;
};

#endif // MENUDIALOG_H
