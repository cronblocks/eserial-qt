#include "serial_interface.h"

#include "macros.h"

#include <QRegularExpression>


#define SETTING_KEY_BAUD_RATE           "BaudRate"
#define SETTING_KEY_DATA_BITS           "DataBits"
#define SETTING_KEY_PARITY              "Parity"
#define SETTING_KEY_STOP_BITS           "StopBits"
#define SETTING_KEY_LINE_ENDING         "LineEnding"
#define SETTING_KEY_INTERLINE_DELAY     "InterlineDelay"


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

    m_interline_delay_ms = static_cast<unsigned int>(
                m_settings_ptr->getUIntValue(
                    SETTING_KEY_INTERLINE_DELAY, 50));

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

    m_settings_ptr->setUIntValue(SETTING_KEY_INTERLINE_DELAY, m_interline_delay_ms);

    m_discvr_ptr->stopDiscoveringPorts();
    m_settings_ptr->saveSettings();
}

void SerialInterface::startSerialPort() {
    if (m_serial_port.isNull() || m_serial_port.isEmpty()) {
        emit errorOccurred("Undefined Serial Port");
    } else {
        if (m_comm_ptr == nullptr) {
            m_comm_ptr = new PortCommunicator(m_serial_port, m_baud_rate, m_data_bits, m_parity, m_stop_bits);

            connect(m_comm_ptr, &PortCommunicator::dataReceived,
                    this,       &SerialInterface::dataReceived);

            connect(m_comm_ptr, &PortCommunicator::errorOccurred,
                    this,       &SerialInterface::errorOccurred);

            m_comm_ptr->startPortCommunication();
        } else {
            emit errorOccurred("Serial Port already opened");
        }
    }
}

void SerialInterface::stopSerialPort() {
    if (m_comm_ptr == nullptr) {
        emit errorOccurred("Serial Port not opened");
    } else {
        m_comm_ptr->stopPortCommunication();
        delete(m_comm_ptr);
        m_comm_ptr = nullptr;
    }
}

// ----------------------
// Setters
// -------------------
void SerialInterface::setSerialPort(const QString& port_name) {
    m_serial_port = QString(port_name).remove(QRegularExpression("\\(.*$")).trimmed();
}

void SerialInterface::setBaudRate(BaudRate baud_rate) {
    m_baud_rate = baud_rate;
}

void SerialInterface::setDataBits(DataBits data_bits) {
    m_data_bits = data_bits;
}

void SerialInterface::setParity(Parity parity) {
    m_parity = parity;
}

void SerialInterface::setStopBits(StopBits stop_bits) {
    m_stop_bits = stop_bits;
}

void SerialInterface::setLineEnding(LineEnding line_ending) {
    m_line_ending = line_ending;
}

void SerialInterface::setInterlineDelay(unsigned int interline_delay) {
    m_interline_delay_ms = interline_delay;
}

// ----------------------
// Getters
// -------------------
BaudRate SerialInterface::getBaudRate() {
    return m_baud_rate;
}

DataBits SerialInterface::getDataBits() {
    return m_data_bits;
}

Parity SerialInterface::getParity() {
    return m_parity;
}

StopBits SerialInterface::getStopBits() {
    return m_stop_bits;
}

LineEnding SerialInterface::getLineEnding() {
    return m_line_ending;
}

unsigned int SerialInterface::getInterlineDelay() {
    return m_interline_delay_ms;
}
