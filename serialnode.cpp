#include "serialnode.h"

SerialNode::SerialNode()
{
    serialPort->setPortName("COM3");
    serialPort->setBaudRate(QSerialPort::Baud9600);
    if (!serialPort->open(QIODevice::ReadOnly)) {
        qDebug() << QObject::tr("Failed to open port, error: %2")
                          .arg(serialPort->errorString())
                       << endl;
    }
}
