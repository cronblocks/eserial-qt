#include "port_communicator.h"

#include "macros.h"

PortCommunicator::PortCommunicator(
                        const QString& serial_port,
                        BaudRate       baud_rate,
                        DataBits       data_bits,
                        Parity         parity,
                        StopBits       stop_bits) {

    m_serial_name = QString(serial_port);
    m_baud_rate   = baud_rate;
    m_data_bits   = data_bits;
    m_parity      = parity;
    m_stop_bits   = stop_bits;

    m_serial = nullptr;
    m_is_running = false;
}

void PortCommunicator::startPortCommunication() {
    if (!isRunning()) {
        start();
    }
}

void PortCommunicator::stopPortCommunication() {
    if (isRunning()) {
        m_is_running = false;
        wait();
    }
}

void PortCommunicator::sendString(const QString& str) {
    m_serial_data_out_mutex.lock();
    m_serial_data_out += str;
    m_serial_data_out_mutex.unlock();
}

void PortCommunicator::run() {
    m_serial = new QSerialPort();

    m_serial->setPortName(m_serial_name);
    m_serial->setBaudRate(static_cast<int>(m_baud_rate));
    m_serial->setDataBits(static_cast<QSerialPort::DataBits>(m_data_bits));

    switch (m_parity) {
        case Parity::None: m_serial->setParity(QSerialPort::NoParity);   break;
        case Parity::Even: m_serial->setParity(QSerialPort::EvenParity); break;
        case Parity::Odd:  m_serial->setParity(QSerialPort::OddParity);  break;
    }

    switch (m_stop_bits) {
        case StopBits::One:       m_serial->setStopBits(QSerialPort::OneStop);        break;
        case StopBits::OnePtFive: m_serial->setStopBits(QSerialPort::OneAndHalfStop); break;
        case StopBits::Two:       m_serial->setStopBits(QSerialPort::TwoStop);        break;
    }

    if (!m_serial->open(QIODevice::ReadWrite)) {
        emit errorOccurred(tr("Can't open %1 (error code %2)")
                           .arg(m_serial_name)
                           .arg(m_serial->error()));
    } else {
        emit portOpened();
        m_is_running = true;
    }

    while (m_is_running) {
        //
    }

    m_serial->close();
    m_serial = nullptr;
    emit portClosed();
}
