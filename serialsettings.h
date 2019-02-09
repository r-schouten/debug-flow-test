#ifndef SERIALSETTINGS_H
#define SERIALSETTINGS_H
#include <QObject>
#include <QSerialPort>

#define DEFAULT_BAUD_RATE 9600

class  SerialSettings{
public:
    QString portName="";
    qint32 baudRate = DEFAULT_BAUD_RATE;
    QSerialPort::FlowControl flowControl = QSerialPort::NoFlowControl;
    QSerialPort::Parity parity = QSerialPort::NoParity;
    QSerialPort::StopBits stopBits = QSerialPort::OneStop;
    QSerialPort::DataBits dataBits = QSerialPort::Data8;

    bool compare(SerialSettings* otherSettings)
    {
        if(baudRate != otherSettings->baudRate) return false;
        if(flowControl != otherSettings->flowControl) return false;
        if(parity != otherSettings->parity) return false;
        if(stopBits != otherSettings->stopBits) return false;
        if(dataBits!= otherSettings->dataBits) return false;
        return true;
    }
};

#endif // SERIALSETTINGS_H
