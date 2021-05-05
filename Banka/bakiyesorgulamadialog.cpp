#include "bakiyesorgulamadialog.h"
#include "ui_bakiyesorgulamadialog.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

bakiyesorgulamaDialog::bakiyesorgulamaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bakiyesorgulamaDialog)
{
    ui->setupUi(this);
}

bakiyesorgulamaDialog::~bakiyesorgulamaDialog()
{
    delete ui;
}
