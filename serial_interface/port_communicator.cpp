#include "port_communicator.h"

#include "macros.h"

#include <QSerialPort>

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

void PortCommunicator::startReception() {
    //
}

void PortCommunicator::stopReception() {
    //
}
