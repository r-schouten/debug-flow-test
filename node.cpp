#include "node.h"

Node::Node(SharedData *sharedData)
    :sharedData(sharedData)
{
    qDebug("node added");
}
