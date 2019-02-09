#ifndef INPUTNODE_H
#define INPUTNODE_H

#include <QObject>
#include "node.h"
#include "shareddata.h"

class InputNode : public Node
{
    Q_OBJECT
public:
    InputNode(SharedData* sharedData);
    bool open = false;
};

#endif // INPUTNODE_H
