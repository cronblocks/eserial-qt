#ifndef PORTDISCOVERER_H
#define PORTDISCOVERER_H


#include <QObject>

#include <list>


class PortDiscoverer : public QObject {

    Q_OBJECT

signals:
    void serialPortAdded(QString&);
    void serialPortRemoved(QString&);

public:
    PortDiscoverer();
    void startDiscoveringPorts();
    void stopDiscoveringPorts();

private:
    std::list<QString> m_available_ports;
};

#endif // PORTDISCOVERER_H
