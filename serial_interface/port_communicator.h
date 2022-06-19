#ifndef PORTCOMMUNICATOR_H
#define PORTCOMMUNICATOR_H


#include <QObject>


class PortCommunicator : public QObject {

    Q_OBJECT

signals:
    void dataReceived(const QString&);
    void errorOccurred(const QString&);

public:
    PortCommunicator();
};

#endif // PORTCOMMUNICATOR_H
