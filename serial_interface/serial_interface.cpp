#include "serial_interface.h"

SerialInterface::SerialInterface() {
    _settings   = new Settings(SETTINGS_FILENAME);
    _discoverer = new PortDiscoverer();
    _communicator = nullptr;

    // --------------
    // Connectors
    // ------------
    connect(_discoverer, &PortDiscoverer::serialPortAdded,
            this,        &SerialInterface::serialPortAdded);

    connect(_discoverer, &PortDiscoverer::serialPortRemoved,
            this,        &SerialInterface::serialPortRemoved);
}

// ----------------------
// Interface control
// -------------------
void SerialInterface::startInterface() {
    //--
}

void SerialInterface::stopInterface() {
    _settings->SaveSettings();
}
