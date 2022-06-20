#ifndef PORTCOMMUNICATOR_H
#define PORTCOMMUNICATOR_H


#include "serial_types.h"

#include <QThread>
#include <QMutex>
#include <QString>
#include <QSerialPort>


class PortCommunicator : public QThread {

    Q_OBJECT

signals:
    void portOpened();
    void portClosed();
    void dataReceived(const QString&);
    void errorOccurred(const QString&);

public:
    PortCommunicator(const QString&, BaudRate, DataBits, Parity, StopBits);

    void startPortCommunication();
    void stopPortCommunication();

    void sendString(const QString&);

private:
    QString      m_serial_port;
    BaudRate     m_baud_rate;
    DataBits     m_data_bits;
    Parity       m_parity;
    StopBits     m_stop_bits;

    QMutex m_mutex;
};

#endif // PORTCOMMUNICATOR_H
