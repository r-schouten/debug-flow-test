#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainNodeScene = new NodeScene(this);                    //create a custom scene
    mainNodeScene->addRect(0,0,50,50);                      //add a rectangle (just for testing)
    ui->Node_Graphicsview->setScene(mainNodeScene);         //add the scene to the graphicsview
}

MainWindow::~MainWindow()
{
    delete ui;
}
