#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include "serialportHandler.h"
#include "shareddata.h"
#include <QObject>
#include <QSerialPort>
class SerialPortManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortManager();
    //SharedData* sharedData;

    QString requestPort(SerialPortHandler*& serialPortHandler, SerialSettings* serialSettings);
    void releasePort(SerialPortHandler* serialPortHandler);
private:
    QList<SerialPortHandler*> serialPortHandlers;


    QString findReader(SerialPortHandler*& resultSerialPortHandler, bool* found, SerialSettings* requestedSerialSettings);
    SerialPortHandler* openNewReader(SerialSettings *seriasSettings);

signals:

public slots:
};

#endif // SERIALPORTMANAGER_H
