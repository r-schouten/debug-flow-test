#include "serialnode.h"

SerialNode::SerialNode(SharedData *sharedData):
InputNode(sharedData)
{
      openPort();

//    serialPort->setPortName("COM35");
//    serialPort->setBaudRate(QSerialPort::Baud9600);
//    if (!serialPort->open(QIODevice::ReadOnly)) {
//        qDebug() << QObject::tr("Failed to open port, error: %2")
//                          .arg(serialPort->errorString())
//                       << endl;
//    }
//    else {
//        qDebug() << QObject::tr("port opened") << endl;
//    }
}
void SerialNode::openPort()
{
    if(serialPortReader != nullptr)
    {
        return;
    }
    //save current settings in serialSettings
    //todo use user defined settings instead of hard coded
    serialSettings.baudRate = 9600;
    serialSettings.parity = QSerialPort::NoParity;
    serialSettings.stopBits = QSerialPort::OneStop;
    serialSettings.flowControl = QSerialPort::NoFlowControl;

    QString potentialError = serialPortManager->requestPort(serialPortReader, &serialSettings);
    if(serialPortReader != nullptr)
    {
        //succesfull opened the port
    }
    else {
        //something went wrong, get error
        errorMessage.append(potentialError);
    }
}
void SerialNode::closePort()
{
    if(serialPortReader == nullptr)
    {
        return;
    }
    serialPortManager->releasePort(serialPortReader);
    serialPortReader = nullptr;

}
