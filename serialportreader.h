#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>
#include <QTimer>
#include <QObject>
#include "serialsettings.h"
class SerialPortReader : public QObject
{
    Q_OBJECT

public:
    explicit SerialPortReader(QSerialPort *serialPort);
    SerialSettings serialSettings;

private:
    QSerialPort *m_serialPort;
    QByteArray m_readData;
    QTextStream m_standardOutput;



private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError error);
};

#endif // SERIALPORTREADER_H
