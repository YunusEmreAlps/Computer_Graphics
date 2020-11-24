#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img = new canvas(this);
    img -> setGeometry(200, 200, 600, 600);
    img -> show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_polygonButton_clicked()
{
    img->drawPolygon();
}
