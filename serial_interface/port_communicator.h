#ifndef PORTCOMMUNICATOR_H
#define PORTCOMMUNICATOR_H


#include <QObject>


class PortCommunicator : public QObject {

    Q_OBJECT

signals:
    void dataReceived(QString&);
    void errorOccurred(QString&);

public:
    PortCommunicator();
};

#endif // PORTCOMMUNICATOR_H
