#include "serial_interface.h"

SerialInterface::SerialInterface() {
    _settings = std::make_unique<Settings>(SETTINGS_FILENAME);
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
