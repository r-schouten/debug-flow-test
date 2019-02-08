#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include "serialportreader.h"
#include "shareddata.h"
#include <QObject>
#include <QSerialPort>
class SerialPortManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortManager(SharedData *sharedData);
    SharedData* sharedData;

private:
    SerialPortReader *serialPortReader;

signals:

public slots:
};

#endif // SERIALPORTMANAGER_H
