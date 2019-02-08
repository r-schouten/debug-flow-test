#include "serialnode.h"

SerialNode::SerialNode(SharedData *sharedData):
InputNode(sharedData)
{

    serialPort->setPortName("COM35");
    serialPort->setBaudRate(QSerialPort::Baud9600);
    if (!serialPort->open(QIODevice::ReadOnly)) {
        qDebug() << QObject::tr("Failed to open port, error: %2")
                          .arg(serialPort->errorString())
                       << endl;
    }
    else {
        qDebug() << QObject::tr("port opened") << endl;
    }
}
