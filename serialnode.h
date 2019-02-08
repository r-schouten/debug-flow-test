#ifndef SERIALNODE_H
#define SERIALNODE_H
#include <QObject>
#include <QtCore>
#include "inputnode.h"
#include "node.h"
#include <QtSerialPort/QSerialPort>
#include <QTextStream>
#include "serialportreader.h"
class SerialNode : public InputNode
{
    Q_OBJECT
private:
    QSerialPort *serialPort = new QSerialPort();
    SerialPortReader *serialPortReader = new SerialPortReader(serialPort);
public:
    SerialNode();
};

#endif // SERIALNODE_H
