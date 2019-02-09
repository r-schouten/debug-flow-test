#include "serialportmanager.h"

SerialPortManager::SerialPortManager()
{

}
QString SerialPortManager::findReader(SerialPortHandler*& resultSerialPortHandler, bool* found, SerialSettings *requestedSerialSettings)
{
    resultSerialPortHandler = nullptr;
    foreach(SerialPortHandler* serialPort, serialPortHandlers)
    {
        if(serialPort->serialSettings->portName.compare( requestedSerialSettings->portName, Qt::CaseInsensitive))
        {//found the same port
            if(serialPort->serialSettings->compare(requestedSerialSettings))
            {
                resultSerialPortHandler = serialPort;
                *found = true;
                return nullptr;//no error
            }
            else {
                *found = true;
                return "A other node is using the same serial port with different settings";
            }
        }
    }
    *found = false;
    return "";
}
SerialPortHandler* SerialPortManager::openNewReader(SerialSettings* serialSettings)
{
    QSerialPort* newPort = new QSerialPort();
    SerialPortHandler* newHandler = new SerialPortHandler(newPort, serialSettings);
    serialPortHandlers.append(newHandler);
    return newHandler;
}
QString SerialPortManager::requestPort(SerialPortHandler *&serialPortHandler, SerialSettings *serialSettings)
{
    serialPortHandler = nullptr;

    SerialPortHandler *foundReader = nullptr;
    bool found = false;
    QString potentialError = findReader(foundReader, &found, serialSettings);
    if(found)
    {
        if(foundReader == nullptr)
        {
             //the node exist but settings are different
             return potentialError;
        }
        else {
            //succesfully found the reader
            serialPortHandler = foundReader;
        }
    }
    else {
       serialPortHandler = openNewReader(serialSettings);
    }
    return "";
}

void SerialPortManager::releasePort(SerialPortHandler *serialPortHandler)
{

}
