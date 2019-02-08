#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    qDebug("started");

    sharedData = new SharedData();
    Node *newNode = new SerialNode(sharedData);
    nodes.append(newNode);
}

MainWindow::~MainWindow()
{
    delete ui;
}
