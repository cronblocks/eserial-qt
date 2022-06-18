#include "serial_interface.h"

SerialInterface::SerialInterface() {
    _settings = std::make_unique<Settings>(SETTINGS_FILENAME);
}


void SerialInterface::StartInterface() {
    //--
}

void SerialInterface::StopInterface() {
    //--
}
