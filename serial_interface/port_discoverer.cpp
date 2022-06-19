#include "port_discoverer.h"

#include "macros.h"

#include <QSerialPortInfo>


#define PORT_ENUMERATION_INTERVAL_MS    500


PortDiscoverer::PortDiscoverer() {
    m_timer = new QTimer(this);
    m_timer->setInterval(PORT_ENUMERATION_INTERVAL_MS);

    connect(m_timer, &QTimer::timeout, this, &PortDiscoverer::findPorts);
}

// -----------------
// Operations
// ---------------
void PortDiscoverer::startDiscoveringPorts() {
    if (!m_timer->isActive()) {
        m_timer->start();
    }
}

void PortDiscoverer::stopDiscoveringPorts() {
    if (m_timer->isActive()) {
        m_timer->stop();
    }
}

// -----------------
// Port Discovery
// ---------------
void PortDiscoverer::findPorts() {
    for (QSerialPortInfo& info : QSerialPortInfo::availablePorts()) {

        bool already_exists = false;

        for (QString& available_name : m_available_ports) {
            if (info.portName() == available_name) {
                already_exists = true;
                break;
            }
        }

        if (!already_exists) {
            m_available_ports.push_back(QString(info.portName()));
            emit serialPortAdded(QString(info.portName()));
        }
    }
}
