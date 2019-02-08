#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QByteArray>
#include <QtSerialPort/QSerialPort>
#include <QTextStream>
#include <QTimer>
#include <QObject>

class SerialPortReader : public QObject
{
    Q_OBJECT

public:
    explicit SerialPortReader(QSerialPort *serialPort, QObject *parent = nullptr);

private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serialPort;
    QByteArray m_readData;
    QTextStream m_standardOutput;
};

#endif // SERIALPORTREADER_H
