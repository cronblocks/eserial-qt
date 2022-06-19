#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H

#include "settings.h"
#include "port_discoverer.h"
#include "port_communicator.h"

#include <QObject>

#include <memory>


#define SETTINGS_FILENAME "Settings.ini"


class SerialInterface : public QObject {

    Q_OBJECT

signals:
    void serialPortAdded(QString&);
    void serialPortRemoved(QString&);
    void dataReceived(QString&);
    void errorOccurred(QString&);

public:
    SerialInterface();
    void StartInterface();
    void StopInterface();

private:
    std::unique_ptr<Settings> _settings;
};

#endif // SERIAL_INTERFACE_H
