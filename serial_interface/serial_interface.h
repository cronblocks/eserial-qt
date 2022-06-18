#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H

#include "settings.h"
#include "port_discoverer.h"
#include "port_communicator.h"

class SerialInterface
{
public:
    SerialInterface();

private:
    static Settings _settings;
};

#endif // SERIAL_INTERFACE_H
