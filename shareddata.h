#ifndef SHAREDDATA_H
#define SHAREDDATA_H

#include <QObject>

class SharedData : public QObject
{
    Q_OBJECT
public:
    explicit SharedData(QObject *parent = nullptr);
    bool running = true;
    //SerialPortManager *serialPortManager = new SerialPortManager();
signals:

public slots:
};

#endif // SHAREDDATA_H
