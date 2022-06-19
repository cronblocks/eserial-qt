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

    // Checking for new ones
    for (QSerialPortInfo& info : QSerialPortInfo::availablePorts()) {

        QString port_desc = info.description().trimmed();
        if (port_desc == "") { port_desc = "_"; }

        QString port_full_name = info.portName().trimmed() + " (" + port_desc + ")";

        bool already_exists = false;

        for (QString& available_name : m_available_ports) {
            if (port_full_name == available_name) {
                already_exists = true;
                break;
            }
        }

        if (!already_exists) {
            m_available_ports.push_back(port_full_name);
            emit serialPortAdded(port_full_name);
        }
    }

    // Checking for removed ones
}
