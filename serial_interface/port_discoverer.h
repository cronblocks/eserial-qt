/*******************************************************************
 * Purpose:
 *     Discovering / enumerating available Serial Ports
 *
 *
 *******************************************************************
 * Author: Usama
 *
 *******************************************************************
 * Changes:
 *
 * Date              Description
 * ----              -----------
 *
 *
 *
 *
 *******************************************************************/

#ifndef PORTDISCOVERER_H
#define PORTDISCOVERER_H


#include <QObject>
#include <QTimer>

#include <list>


class PortDiscoverer : public QObject {

    Q_OBJECT

signals:
    void serialPortAdded(const QString&);
    void serialPortRemoved(const QString&);

public:
    PortDiscoverer();
    void startDiscoveringPorts();
    void stopDiscoveringPorts();

private:
    std::list<QString> m_available_ports;
    QTimer *m_timer;

    void enumeratePorts();
};

#endif // PORTDISCOVERER_H
