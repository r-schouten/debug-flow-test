#ifndef SERIALNODE_H
#define SERIALNODE_H
#include <QObject>
#include <QtCore>
#include "inputnode.h"
#include "node.h"
#include <QtSerialPort/QSerialPort>
#include <QTextStream>
#include "serialportreader.h"
#include "shareddata.h"
#include "serialportmanager.h"
class SerialNode : public InputNode
{
    Q_OBJECT
private:
    QSerialPort *serialPort = new QSerialPort();
    SerialPortManager *serialPortManager = new SerialPortManager(sharedData);
public:
    SerialNode(SharedData *sharedData);
};

#endif // SERIALNODE_H
