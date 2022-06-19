#ifndef PORTDISCOVERER_H
#define PORTDISCOVERER_H


#include <QObject>


class PortDiscoverer : public QObject {

    Q_OBJECT

signals:
    void serialPortAdded(QString&);
    void serialPortRemoved(QString&);

public:
    PortDiscoverer();
};

#endif // PORTDISCOVERER_H
