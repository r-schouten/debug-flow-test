#include "serialportmanager.h"

SerialPortManager::SerialPortManager(SharedData* sharedData)
    :sharedData(sharedData)
{

}
QString SerialPortManager::findReader(SerialPortReader* resultSerialPortReader, SerialSettings requestedSerialSettings)
{
    resultSerialPortReader = nullptr;
    foreach(SerialPortReader* serialPort, serialPortReaders)
    {
        if(serialPort->serialSettings.portName.compare( requestedSerialSettings.portName),Qt::CaseInsensitive)
        {//found the same port
            if(serialPort->serialSettings.compare(requestedSerialSettings))
            {
                resultSerialPortReader = serialPort;
                return nullptr;//no error
            }
            else {
                return "A other node is using the same serial port with different settings";
            }
        }
    }
    return "";
}
QString SerialPortManager::requestPort(SerialPortReader *serialPortReader, SerialPortManager::SerialSettings *serialSettings)
{
    SerialPortReader *foundReader;
    QString potentialError = findPort(foundReader, serialSettings);
}

void SerialPortManager::releasePort(SerialPortReader *serialPortReader)
{

}
