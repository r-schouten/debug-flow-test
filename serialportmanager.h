#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include "serialportreader.h"
#include "shareddata.h"
#include <QObject>
#include <QSerialPort>
#include "serialsettings.h"
class SerialPortManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortManager(SharedData *sharedData);
    SharedData* sharedData;

    QString requestPort(SerialPortReader* serialPortReader, SerialSettings* serialSettings);
    void releasePort(SerialPortReader* serialPortReader);
private:
    QList<SerialPortReader*> serialPortReaders;


    QString findReader(SerialPortReader *resultSerialPortReader, SerialSettings requestedSerialSettings);
signals:

public slots:
};

#endif // SERIALPORTMANAGER_H
