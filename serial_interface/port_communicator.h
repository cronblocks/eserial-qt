#ifndef PORTCOMMUNICATOR_H
#define PORTCOMMUNICATOR_H


#include "serial_types.h"

#include <QObject>
#include <QString>


class PortCommunicator : public QObject {

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

private:
    QString      m_serial_port;
    BaudRate     m_baud_rate;
    DataBits     m_data_bits;
    Parity       m_parity;
    StopBits     m_stop_bits;
};

#endif // PORTCOMMUNICATOR_H
