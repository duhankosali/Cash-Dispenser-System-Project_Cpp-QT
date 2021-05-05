#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menudialog.h" // menudialog header imizi ekledik.

#include <QFile>
#include <QTextStream>

double numbers = 0.0; // sayılar adında bir değişken tanımladık.
int sayac=0; // 3 hatalı girişte program kapanır.

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Numaralar için ayrılmış bölüm
    ui->Display->setText(QString::number(numbers));
    QPushButton *numButtons[10];

    for (int i=0; i<10; i++) {
        QString butName = "button" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()),this,SLOT(NumPressed()));
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed() // Numaralar için yazdığımız fonksiyon
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



void MainWindow::on_pushButton_10_clicked() // butona basınca diğer form a geçme kodu
{
    //MenuDialog menuDialog;
   // menuDialog.setModal(true);
    //menuDialog.exec();

    ui->Display->setText("");
    hide(); // 1. penceremizi gizler.
    menuDialog = new MenuDialog(this);
    menuDialog->show();


}

void MainWindow::on_buttonENTER_clicked()
{



    QFile file("D:/QtProject/Banka/musteri");

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
     //   QMessageBox::warning(this, "title","file not open"); // MessageBox ile hata mesajı.
    }

    QString pass = ui->Display->text();

    if(pass.size()==4)
    {
        QTextStream out (&file);
        QString text = ui->Display->text(); // Müşterinin şifresini yazdırıyoruz
        out << text;
        file.flush();
        file.close();

         //hide(); // 1. penceremizi gizler.
         menuDialog = new MenuDialog(this);
         menuDialog->show();
    }

    else
    {
        QMessageBox::warning(this, "Error","Hatalı şifre girdiniz!"); // MessageBox ile hata mesajı.
       mainWindow->close();
    }




}
