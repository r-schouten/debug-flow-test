#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug("started");
    Node *newNode = new SerialNode();
    nodes.append(newNode);
}

MainWindow::~MainWindow()
{
    delete ui;
}
