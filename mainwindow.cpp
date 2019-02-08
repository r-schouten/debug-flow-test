#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainNodeScene = new NodeScene(this);
    mainNodeScene->addRect(0,0,50,50);
    ui->Node_Graphicsview->setScene(mainNodeScene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
