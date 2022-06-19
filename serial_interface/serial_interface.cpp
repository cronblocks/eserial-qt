#include "serial_interface.h"

#include "macros.h"


#define SETTING_KEY_BAUD_RATE       "BaudRate"
#define SETTING_KEY_DATA_BITS       "DataBits"
#define SETTING_KEY_PARITY          "Parity"
#define SETTING_KEY_STOP_BITS       "StopBits"
#define SETTING_KEY_LINE_ENDING     "LineEnding"


SerialInterface::SerialInterface() {
    m_settings_ptr = new Settings(SETTINGS_FILENAME);
    m_discvr_ptr   = new PortDiscoverer();
    m_comm_ptr     = nullptr;

    m_baud_rate = static_cast<BaudRate>(
                m_settings_ptr->getIntValue(
                    SETTING_KEY_BAUD_RATE, static_cast<int>(BaudRate::_115200)));

    m_data_bits = static_cast<DataBits>(
                m_settings_ptr->getIntValue(
                    SETTING_KEY_DATA_BITS, static_cast<int>(DataBits::_8)));

    m_parity = static_cast<Parity>(
                m_settings_ptr->getIntValue(
                    SETTING_KEY_PARITY, static_cast<int>(Parity::None)));

    m_stop_bits = static_cast<StopBits>(
                m_settings_ptr->getIntValue(
                    SETTING_KEY_STOP_BITS, static_cast<int>(StopBits::One)));

    m_line_ending = static_cast<LineEnding>(
                m_settings_ptr->getIntValue(
                    SETTING_KEY_LINE_ENDING, static_cast<int>(LineEnding::LF)));

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
    m_settings_ptr->setIntValue( SETTING_KEY_BAUD_RATE,   static_cast<int>( m_baud_rate   ));
    m_settings_ptr->setIntValue( SETTING_KEY_DATA_BITS,   static_cast<int>( m_data_bits   ));
    m_settings_ptr->setIntValue( SETTING_KEY_PARITY,      static_cast<int>( m_parity      ));
    m_settings_ptr->setIntValue( SETTING_KEY_STOP_BITS,   static_cast<int>( m_stop_bits   ));
    m_settings_ptr->setIntValue( SETTING_KEY_LINE_ENDING, static_cast<int>( m_line_ending ));

    m_discvr_ptr->stopDiscoveringPorts();
    m_settings_ptr->saveSettings();
}
