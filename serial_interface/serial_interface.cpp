#include "serial_interface.h"

#include "macros.h"

SerialInterface::SerialInterface() {
    m_settings_ptr = new Settings(SETTINGS_FILENAME);
    m_discvr_ptr   = new PortDiscoverer();
    m_comm_ptr     = nullptr;

    m_baud_rate   = BaudRate::_115200;
    m_data_bits   = DataBits::_8;
    m_parity      = Parity::None;
    m_stop_bits   = StopBits::One;
    m_line_ending = LineEnding::LF;

    // --------------
    // Connectors
    // ------------
    connect(m_discvr_ptr, &PortDiscoverer::serialPortAdded,
            this,         &SerialInterface::serialPortAdded);

    connect(m_discvr_ptr, &PortDiscoverer::serialPortRemoved,
            this,         &SerialInterface::serialPortRemoved);
}

// ----------------------
// Interface control
// -------------------
void SerialInterface::startInterface() {
    m_discvr_ptr->startDiscoveringPorts();
}

void SerialInterface::stopInterface() {
    m_discvr_ptr->stopDiscoveringPorts();
    m_settings_ptr->saveSettings();
}
