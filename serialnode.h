#ifndef SERIALNODE_H
#define SERIALNODE_H
#include <QObject>
#include <QtCore>
#include "inputnode.h"
#include "node.h"
#include <QTextStream>
#include <QSerialPort>
#include "serialportreader.h"
#include "shareddata.h"
#include "serialportmanager.h"
class SerialNode : public InputNode
{
    Q_OBJECT
private:
    //the serial port manager provides the serialPortReader object, because a serial port can be used for multiple nodes
    SerialPortManager *serialPortManager = new SerialPortManager(sharedData);

    //the serial object where the data comes from
    SerialPortReader* serialPortReader = nullptr;

    SerialPortManager::SerialSettings serialSettings;

    void openPort();
    void closePort();
public:
    SerialNode(SharedData *sharedData);
};

#endif // SERIALNODE_H
