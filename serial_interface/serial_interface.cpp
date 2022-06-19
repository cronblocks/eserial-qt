#include "serial_interface.h"

SerialInterface::SerialInterface() {
    _settings   = std::make_unique<Settings>(SETTINGS_FILENAME);
    _discoverer = std::make_unique<PortDiscoverer>();
    _communicator = nullptr;
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
