#ifndef BAKIYESORGULAMADIALOG_H
#define BAKIYESORGULAMADIALOG_H

#include <QDialog>
#include <QMainWindow>


namespace Ui {
class bakiyesorgulamaDialog;
}

class bakiyesorgulamaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit bakiyesorgulamaDialog(QWidget *parent = nullptr);
    ~bakiyesorgulamaDialog();

private:
    Ui::bakiyesorgulamaDialog *ui;
};

#endif // BAKIYESORGULAMADIALOG_H
