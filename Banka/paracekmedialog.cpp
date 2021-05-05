#include "paracekmedialog.h"
#include "ui_paracekmedialog.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>

paracekmeDialog::paracekmeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paracekmeDialog)
{
    ui->setupUi(this);

    // Numaralar için ayrılmış bölüm
    MainWindow mainWindow;

    ui->Display->setText(QString::number(mainWindow.bakiye));
    QPushButton *numButtons[10];

    for (int i=0; i<10; i++) {
        QString butName = "button" + QString::number(i);
        numButtons[i] = paracekmeDialog::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()),this,SLOT(NumPressed()));
    }



}

paracekmeDialog::~paracekmeDialog()
{
    delete ui;

}

void paracekmeDialog::NumPressed() // Numaralar için yazdığımız fonksiyon
{
    QPushButton *button = (QPushButton *)sender();
    QString butval = button->text();
    QString displayVal = ui->Display->text();

    if ((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0) ) {
        ui->Display->setText(butval);
    }
    else {
        QString newval = displayVal + butval;
        double dblNewVal = newval.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g', 16));
    }
}

void paracekmeDialog::on_buttonENTER_clicked()
{
    MainWindow mainWindow;
    MenuDialog menuDialog;


    QFile filemusteri ("D:/QtProject/Banka/musteri");

    if (!filemusteri.open(QFile::ReadOnly | QFile::Text))
    {
      //  QMessageBox::warning(this, "title", "file not open"); // MessageBox ile hata mesajı
    }

    QTextStream in2 (&filemusteri);
    QString musteri = in2.readAll();
    filemusteri.close();

    QString yol = ("D:/QtProject/Banka/"+musteri);




    QFile file(yol);

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
      //  QMessageBox::warning(this, "title", "file not open"); // MessageBox ile hata mesajı
    }
    QTextStream in (&file);
    QString text = in.readAll();

    file.close();

    int bakiyeValue = text.toInt();

    QString cekilenparaStr = ui->Display->text();
    bool ok;
    int cekilenpara = cekilenparaStr.toInt(&ok);
    if (!ok) {
      // conversion failed
    }

    bakiyeValue = bakiyeValue - cekilenpara;

    if (bakiyeValue<0)
    {
        QMessageBox msgbox;
        msgbox.setText("Hesabınızda yeteri kadar bakiye bulunmamaktadır! Lütfen tekrar deneyiniz.");
        msgbox.exec();
    }

    else
    {

    text = QString::number(bakiyeValue);

    // Text dosyası kısmı

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
     //   QMessageBox::warning(this, "title","file not open"); // MessageBox ile hata mesajı.
    }
    QTextStream out (&file);
   // QString text = ui->Display->text();
    out << text;
    file.flush();
    file.close();
 }
    // text dosyası kısmı sonu

    if(bakiyeValue>=0)
    {
        QMessageBox msg;
        msg.setText("Para Çekme İşleminiz Başarıyla Gerçekleşti");
        msg.exec();
    }



        ui->Display->setText("");
        hide();
        menuDialog.show();

}

void paracekmeDialog::on_pushButton_clicked()
{
    MenuDialog menuDialog;

    ui->Display->setText("");
    hide();
    menuDialog.show();
}
