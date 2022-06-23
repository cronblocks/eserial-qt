#ifndef PORTCOMMUNICATOR_H
#define PORTCOMMUNICATOR_H


#include "serial_interface.h"

#include <QThread>
#include <QString>


class FileLinesProvider : public QThread {

    Q_OBJECT

signals:
    void provisionStarted();
    void provisionCompleted();
    void provisionPercentageUpdated(float);
    void errorOccurred(const QString&);

public:
    FileLinesProvider(SerialInterface *, const QString&);

    void startProvision();
    void stopProvision();

private:
    void run() override;
    int countFileLines();

    SerialInterface   *m_serial_iface_ptr;
    QString           m_filename;

    volatile bool m_is_running;
};

#endif // PORTCOMMUNICATOR_H
