#include "serialportHandler.h"

SerialPortHandler::SerialPortHandler(QSerialPort *serialPort, SerialSettings* serialSettings) :
    m_serialPort(serialPort),
    serialSettings(serialSettings),
    m_standardOutput(stdout)
{
    configurePort();

    bool succes = m_serialPort->open(QIODevice::ReadWrite);
    if(succes)
    {
        open = true;
        connect(m_serialPort, &QSerialPort::readyRead, this, &SerialPortHandler::handleReadyRead);
        connect(m_serialPort, &QSerialPort::errorOccurred, this, &SerialPortHandler::handleError);
    }
    else {
        errorOccured = true;
        readError(m_serialPort->error());
    }
}
SerialPortHandler::~SerialPortHandler()
{
    delete m_serialPort;
    delete serialSettings;
}
void SerialPortHandler::readError(QSerialPort::SerialPortError error)
{
    if(error == QSerialPort::SerialPortError::NoError)
    {
        //expect this should never happen
        errorMessage = "No error occurred";
    }
    else if(error == QSerialPort::SerialPortError::DeviceNotFoundError)
    {
        errorMessage = "An error occurred while attempting to open an non-existing device";
    }
    else if(error == QSerialPort::SerialPortError::PermissionError)
    {
        errorMessage = "An error occurred while attempting to open an already opened device by another process or a user not having enough permission and credentials to open";
    }
    else if(error == QSerialPort::SerialPortError::OpenError)
    {
        errorMessage = "An error occurred while attempting to open an already opened device in this object";
    }
    else if(error == QSerialPort::SerialPortError::NotOpenError)
    {
        errorMessage = "This error occurs when an operation is executed that can only be successfully performed if the device is open.";
    }
    else if(error == QSerialPort::SerialPortError::ParityError)
    {
        errorMessage = "Parity error detected by the hardware while reading data.";
    }
    else if(error == QSerialPort::SerialPortError::FramingError)
    {
        errorMessage = "Framing error detected by the hardware while reading data.";
    }
    else if(error == QSerialPort::SerialPortError::BreakConditionError)
    {
        errorMessage = "Break condition detected by the hardware on the input line.";
    }
    else if(error == QSerialPort::SerialPortError::WriteError)
    {
        errorMessage = "An I/O error occurred while writing the data";
    }
    else if(error == QSerialPort::SerialPortError::ReadError)
    {
        errorMessage = "An I/O error occurred while reading the data";
    }
    else if(error == QSerialPort::SerialPortError::ResourceError)
    {
        errorMessage = "An I/O error occurred when a resource becomes unavailable, e.g. when the device is unexpectedly removed from the system";
    }
    else if(error == QSerialPort::SerialPortError::UnsupportedOperationError)
    {
        errorMessage = "The requested device operation is not supported or prohibited by the running operating system.";
    }
    else if(error == QSerialPort::SerialPortError::TimeoutError)
    {
        errorMessage = "A timeout error occurred";
    }
    else if(error == QSerialPort::SerialPortError::UnknownError)
    {
        errorMessage = "An unidentified error occurred";
    }
    else {
        errorMessage = "An unknown error occurred";
    }
    qDebug() << errorMessage;
    //m_serialPort->clearError();
}
void SerialPortHandler::configurePort()
{
    m_serialPort->setPortName( serialSettings->portName);
    m_serialPort->setBaudRate( serialSettings->baudRate);
    m_serialPort->setDataBits( serialSettings->dataBits);
    m_serialPort->setFlowControl( serialSettings->flowControl);
    m_serialPort->setParity( serialSettings->parity);
    m_serialPort->setStopBits( serialSettings->stopBits);
}
void SerialPortHandler::handleReadyRead()
{
    #define MAX_READ_LEN 1000
    qDebug() << m_serialPort->read(MAX_READ_LEN);
}

void SerialPortHandler::handleError(QSerialPort::SerialPortError serialPortError)
{
    readError(serialPortError);
    errorOccured = true;
    m_serialPort->close();
    open = false;
}
