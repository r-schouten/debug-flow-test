#ifndef SerialPortHandler_H
#define SerialPortHandler_H

#include <QtCore>
#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>
#include <QTimer>
#include <QObject>
#include <QIODevice>
#include "serialsettings.h"
class SerialPortHandler : public QObject
{
    Q_OBJECT

public:
    explicit SerialPortHandler(QSerialPort *serialPort, SerialSettings* serialSettings);
    SerialSettings* serialSettings;

private:
    QSerialPort *m_serialPort;
    QByteArray m_readData;
    QTextStream m_standardOutput;

    QString errorMessage;
    bool errorOccured = false;
    bool open = false;

    void configurePort();
    ~SerialPortHandler();
    void readError(QSerialPort::SerialPortError error);
private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError error);
};

#endif // SerialPortHandler_H
