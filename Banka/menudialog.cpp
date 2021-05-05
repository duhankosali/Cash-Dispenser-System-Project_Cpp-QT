#include "menudialog.h"
#include "ui_menudialog.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

//Text dosyaları için kütüphane
#include <QFile>
#include <QTextStream>

MenuDialog::MenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuDialog)
{
    ui->setupUi(this);

    parayatirdialog = new parayatirDialog(this);
    paracekmedialog = new paracekmeDialog(this);


}

MenuDialog::~MenuDialog()
{
    delete ui;
}

void MenuDialog::on_pushButton_clicked()
{
   // hide(); // 1. penceremizi gizler.
    //paracekmedialog = new paracekmeDialog(this);
    paracekmedialog->show();


}

void MenuDialog::on_pushButton_2_clicked()
{
    // hide(); // 1. penceremizi gizler.

    //parayatirdialog = new parayatirDialog(this);
    parayatirdialog->show();


}

void MenuDialog::on_pushButton_3_clicked()
{

    //hide(); // 1. penceremizi gizler.
    //bakiyesorgulamadialog = new bakiyesorgulamaDialog(this);
    //bakiyesorgulamadialog->show();

   MainWindow mainWindow;

   QString bakiyeStr = QString::number(mainWindow.bakiye);


   QFile filemusteri ("D:/QtProject/Banka/musteri");

   if (!filemusteri.open(QFile::ReadOnly | QFile::Text))
   {
      // QMessageBox::warning(this, "title", "file not open"); // MessageBox ile hata mesajı
   }

   QTextStream in2 (&filemusteri);
   QString musteri = in2.readAll();
   filemusteri.close();

   QString yol = ("D:/QtProject/Banka/"+musteri);


   //text dosyası kısmı başlangıç

   QFile file(yol);

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
       // QMessageBox::warning(this, "title", "file not open"); // MessageBox ile hata mesajı
    }
    QTextStream in (&file);
    QString text = in.readAll();

    QMessageBox msgbox;
    msgbox.setText("Mevcut Bakiyeniz: "+ text + "TL'dir.");
    msgbox.exec();

    file.close();

    //text dosyası kısmı sonu

   menuDialog = new MenuDialog(this);
   menuDialog->show();
   menuDialog->close();
}
