#include "port_communicator.h"

#include "macros.h"

#include <QMutexLocker>


#define TIMEOUT_TRANSMIT_DATA_MS   50
#define TIMEOUT_RECEIVE_DATA_MS    50


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
    const QMutexLocker locker(&m_serial_data_out_mutex);
    m_serial_data_out += str;
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
        if (transmitSerialData() != 0) {
            break;
        }

        if (receiveSerialData() != 0) {
            break;
        }
    }

    m_serial->close();
    m_serial = nullptr;

    emit portClosed();
}

int PortCommunicator::transmitSerialData() {
    const QMutexLocker locker(&m_serial_data_out_mutex);

    if (!m_serial_data_out.isNull() &&
            !m_serial_data_out.isEmpty()) {
        
        const QByteArray send_array = m_serial_data_out.toUtf8();

        m_serial->write(send_array);

        if (!m_serial->waitForBytesWritten(TIMEOUT_TRANSMIT_DATA_MS)) {
            return -1;
        } else {
            m_serial_data_out.clear();
        }
    }

    return 0;
}

int PortCommunicator::receiveSerialData() {
    QByteArray receive_array = m_serial->readAll();

    if (m_serial->waitForReadyRead(TIMEOUT_RECEIVE_DATA_MS)) {
        receive_array += m_serial->readAll();
    }

    if (!receive_array.isNull() &&
            !receive_array.isEmpty()) {
        emit dataReceived(QString(receive_array.data()));
    }

    return 0;
}
