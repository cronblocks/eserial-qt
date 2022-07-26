/*******************************************************************
 * Purpose:
 *     Discovering / enumerating available Serial Ports
 *
 *
 *******************************************************************
 * Author: Usama
 *
 *******************************************************************
 * Changes:
 *
 * Date              Description
 * ----              -----------
 *
 *
 *
 *
 *******************************************************************/

#include "port_discoverer.h"

#include "macros.h"

#include <QSerialPortInfo>


#define PORT_ENUMERATION_INTERVAL_MS    500


PortDiscoverer::PortDiscoverer() {
    m_timer = new QTimer(this);
    m_timer->setInterval(PORT_ENUMERATION_INTERVAL_MS);

    connect(m_timer, &QTimer::timeout, this, &PortDiscoverer::enumeratePorts);
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
static QString getPortNameWithDescription(const QSerialPortInfo& port_info) {
    QString port_desc = port_info.description().trimmed();

    if (port_desc != "") { port_desc = " (" + port_desc + ")"; }

    return port_info.portName().trimmed() + port_desc;
}

void PortDiscoverer::enumeratePorts() {

    // Checking for new ones
    for (QSerialPortInfo& info : QSerialPortInfo::availablePorts()) {

        QString info_full_name = getPortNameWithDescription(info);

        bool exists = false;

        for (QString& available_full_name : m_available_ports) {
            if (info_full_name == available_full_name) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            m_available_ports.push_back(info_full_name);
            emit serialPortAdded(info_full_name);
        }
    }

    // Checking for removed ones
    std::list<QString> ports_to_be_removed;

    for (QString& available_full_name : m_available_ports) {

        bool exists = false;

        for (QSerialPortInfo& info : QSerialPortInfo::availablePorts()) {

            QString info_full_name = getPortNameWithDescription(info);;

            if (info_full_name == available_full_name) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            ports_to_be_removed.push_back(available_full_name);
            emit serialPortRemoved(available_full_name);
        }
    }

    for (QString& removal_full_name : ports_to_be_removed) {
        m_available_ports.remove(removal_full_name);
    }
}
