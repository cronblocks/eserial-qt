#include "port_communicator.h"

#include "macros.h"

PortCommunicator::PortCommunicator(
                        const QString& serial_port,
                        BaudRate       baud_rate,
                        DataBits       data_bits,
                        Parity         parity,
                        StopBits       stop_bits) {

    m_serial_port = QString(serial_port);
    m_baud_rate   = baud_rate;
    m_data_bits   = data_bits;
    m_parity      = parity;
    m_stop_bits   = stop_bits;
}

void PortCommunicator::startPortCommunication() {
    emit dataReceived("Test Data 1");
    emit errorOccurred("Test Error 1");
}

void PortCommunicator::stopPortCommunication() {
    emit dataReceived("Test Data 2");
    emit errorOccurred("Test Error 2");
}

void PortCommunicator::sendString(const QString& str) {
    //--
}
