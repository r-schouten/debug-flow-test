#ifndef NODESCENE_H
#define NODESCENE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>

class NodeScene : public QGraphicsScene
{
public:
    NodeScene(QObject *parent = nullptr);
};

#endif // NODESCENE_H
