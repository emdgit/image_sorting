#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->loadImage("D:\\ФОТО\\SONY_Ericson_C702i\\DCIM\\100MSDCF\\DSC01147.JPG");
}

MainWindow::~MainWindow()
{
    delete ui;
}

