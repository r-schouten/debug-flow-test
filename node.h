#ifndef NODE_H
#define NODE_H

#include "shareddata.h"

#include <QObject>

class Node : public QObject
{
    Q_OBJECT
private:
public:
    Node(SharedData* sharedData);
    SharedData* sharedData;
    bool error = false;
    QString errorMessage = "";
};

#endif // NODE_H
