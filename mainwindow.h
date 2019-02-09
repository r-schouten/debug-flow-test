#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "nodescene.h"

#include <QObject>
#include "Node.h"
#include "inputnode.h"
#include "serialnode.h"
#include "shareddata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    NodeScene *mainNodeScene;   // the scene where all the nodes will be place
    QList<Node*> nodes;
    SharedData *sharedData;

};

#endif // MAINWINDOW_H
