#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H

#include "settings.h"
#include "port_discoverer.h"
#include "port_communicator.h"

#define SETTINGS_FILENAME "Settings.ini"

class SerialInterface
{
public:
    SerialInterface();

private:
    std::unique_ptr<Settings> _settings;
};

#endif // SERIAL_INTERFACE_H
