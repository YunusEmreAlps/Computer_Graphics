#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
#include <QPainter>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    img = new resim(this);
    img->setGeometry(50,50,800,800);
    img->anaform = this;
    showMaximized();
}

MainWindow::~MainWindow()
{    
    delete ui;
}

void MainWindow::statuseYaz(QString X, QString Y)
{
    ui->statusBar->showMessage("X = " + X + "  Y = " + Y);
}


void MainWindow::on_pushButton_clicked()
{
   bool kontrol;
   kontrol = img->resmiKaydet("/home/vahit/deneme.bmp");
   if (kontrol) {
       QMessageBox::information(this,"Kayıt Bildiri","Resim Başarıyla kaydedildi");
   } else {
       QMessageBox::information(this,"Kayıt Bildiri","Upps bir sorun var!!!");
   }
}

void MainWindow::on_pushButton_2_clicked()
{
    hangiEgri = 0;
    img->cizBezier();
}

void MainWindow::on_pushButton_3_clicked()
{
    img->dugumK = ui->lineEdit_2->text().toInt();
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        img->dugumVektor.push_back(ui->listWidget->item(i)->text().toDouble());
    }
    hangiEgri = 1;
    img->cizBspline();
}

void MainWindow::on_lineEdit_returnPressed()
{
    ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->clear();
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    ui->listWidget->takeItem(ui->listWidget->currentIndex().row())->text();
}
