#ifndef NODE_H
#define NODE_H

#include "shareddata.h"
#include <QPainter>
#include <QGraphicsItem>
#include <QObject>

class Node : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
public:
    Node(SharedData* sharedData);
    SharedData* sharedData;
    bool error = false;
    QString errorMessage = "";

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // NODE_H
