#ifndef SERIALNODE_H
#define SERIALNODE_H
#include <QObject>
#include <QtCore>
#include "inputnode.h"
#include "node.h"
#include <QTextStream>
#include <QSerialPort>
#include "serialportHandler.h"
#include "shareddata.h"
#include "serialportmanager.h"
#include "serialsettings.h"
class SerialNode : public InputNode
{
    Q_OBJECT
private:
    //the serial port manager provides the serialPortReader object, because a serial port can be used for multiple nodes
    SerialPortManager *serialPortManager = new SerialPortManager();

    //the serial object where the data comes from
    SerialPortHandler* serialPortHandler = nullptr;

    SerialSettings serialSettings;


public:
    SerialNode(SharedData *sharedData);
    void openPort();
    void closePort();
};

#endif // SERIALNODE_H
