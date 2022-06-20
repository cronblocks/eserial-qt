#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H


#include "serial_types.h"
#include "settings.h"
#include "port_discoverer.h"
#include "port_communicator.h"

#include <QObject>
#include <QString>


#define SETTINGS_FILENAME "Settings.ini"


class SerialInterface : public QObject {

    Q_OBJECT

signals:
    void serialPortAdded(const QString&);
    void serialPortRemoved(const QString&);
    void portOpened();
    void portClosed();
    void dataReceived(const QString&);
    void errorOccurred(const QString&);

public:
    SerialInterface();

    void startInterface();
    void stopInterface();
    void startSerialPort();
    void stopSerialPort();

    void sendTextLineToSerialPort(const QString&);
    void sendTextFileToSerialPort(const QString&);

    void setSerialPort(const QString&);
    void setBaudRate(BaudRate);
    void setDataBits(DataBits);
    void setParity(Parity);
    void setStopBits(StopBits);
    void setLineEnding(LineEnding);
    void setInterlineDelay(unsigned int);

    BaudRate     getBaudRate();
    DataBits     getDataBits();
    Parity       getParity();
    StopBits     getStopBits();
    LineEnding   getLineEnding();
    unsigned int getInterlineDelay();

private:
    Settings         *m_settings_ptr;
    PortDiscoverer   *m_discvr_ptr;
    PortCommunicator *m_comm_ptr;

    QString      m_serial_port;
    BaudRate     m_baud_rate;
    DataBits     m_data_bits;
    Parity       m_parity;
    StopBits     m_stop_bits;
    LineEnding   m_line_ending;
    unsigned int m_interline_delay_ms;
};

#endif // SERIAL_INTERFACE_H
