#include "serialportreader.h"

SerialPortReader::SerialPortReader(QSerialPort *serialPort) :
    m_serialPort(serialPort),
    m_standardOutput(stdout)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialPortReader::handleReadyRead);
    connect(m_serialPort, &QSerialPort::errorOccurred, this, &SerialPortReader::handleError);
}

void SerialPortReader::handleReadyRead()
{

    qDebug(m_serialPort->readLine());
}


void SerialPortReader::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        m_standardOutput << QObject::tr("An I/O error occurred while reading "
                                        "the data from port %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << endl;
    }
}
