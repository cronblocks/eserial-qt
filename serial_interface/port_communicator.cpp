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

    m_is_running = false;
}

void PortCommunicator::startPortCommunication() {
    if (!isRunning()) {
        m_is_running = true;
        start();
    }
}

void PortCommunicator::stopPortCommunication() {
    if (isRunning()) {
        m_is_running = false;
    }
}

void PortCommunicator::sendString(const QString& str) {
    //--
}

void PortCommunicator::run() {
    while (m_is_running) {
        //
    }
}
