#include "serialnode.h"

SerialNode::SerialNode(SharedData *sharedData):
InputNode(sharedData)
{

}
void SerialNode::openPort()
{
    if(serialPortHandler != nullptr)
    {
        return;
    }
    //save current settings in serialSettings
    //todo use user defined settings instead of hard coded
    serialSettings.portName = "COM8";
    serialSettings.baudRate = 2000000;
    serialSettings.parity = QSerialPort::NoParity;
    serialSettings.stopBits = QSerialPort::OneStop;
    serialSettings.flowControl = QSerialPort::NoFlowControl;
    serialSettings.dataBits = QSerialPort::Data8;
    QString potentialError = serialPortManager->requestPort(serialPortHandler, &serialSettings);

    if(serialPortHandler != nullptr)
    {
        //succesfull opened the port
    }
    else {
        //something went wrong, get error
        errorMessage.append(potentialError);
        qDebug() << errorMessage;
    }
}
void SerialNode::closePort()
{
    if(serialPortHandler == nullptr)
    {
        return;
    }
    serialPortManager->releasePort(serialPortHandler);
    serialPortHandler = nullptr;

}
