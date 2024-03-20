/*******************************************************************
 * Purpose:
 *     Providing GUI application with a single interface to all of
 * Serial Ports functionality.
 *
 *******************************************************************
 * Author: Usama
 *
 *******************************************************************
 * Changes:
 *     Date         Changed by      Description
 *     ----         ----------      -----------
 *
 *******************************************************************/

#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H


#include "serial_types.h"
#include "settings.h"
#include "port_discoverer.h"
#include "port_communicator.h"
#include "file_lines_provider.h"

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
    void fileTxnStarted();
    void fileTxnCompleted();
    void fileTxnPercentageUpdated(float);
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
    Settings          *m_settings_ptr;
    PortDiscoverer    *m_discvr_ptr;
    PortCommunicator  *m_comm_ptr;
    FileLinesProvider *m_file_provider_ptr;

    QString      m_serial_port;
    BaudRate     m_baud_rate;
    DataBits     m_data_bits;
    Parity       m_parity;
    StopBits     m_stop_bits;
    LineEnding   m_line_ending;
    unsigned int m_interline_delay_ms;

    void onPortError(const QString&);
    void onPortClosed();
    void onFileTransmissionCompleted();
};

#endif // SERIAL_INTERFACE_H
