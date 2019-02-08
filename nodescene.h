#ifndef NODESCENE_H
#define NODESCENE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>

class NodeScene : public QGraphicsScene   // pass parent to qgraphicsscene to prevent memory leak when deleting?!?
{
public:
    NodeScene(QObject *parent = nullptr);
};

#endif // NODESCENE_H
