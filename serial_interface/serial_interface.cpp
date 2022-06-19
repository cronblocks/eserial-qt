#include "serial_interface.h"

SerialInterface::SerialInterface() {
    _settings   = new Settings(SETTINGS_FILENAME);
    _discoverer = new PortDiscoverer();
    _communicator = nullptr;

    connect(_discoverer, &PortDiscoverer::serialPortAdded,
            this, &SerialInterface::serialPortAdded);
}

// -----------------
// Interface controls
// --------------
void SerialInterface::startInterface() {
    //--
}

void SerialInterface::stopInterface() {
    _settings->SaveSettings();
}
