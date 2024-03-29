/*******************************************************************
 * Purpose:
 *     Providing text lines from a given file for transmission over
 * a Serial Port.
 *
 *******************************************************************
 * Author: Usama
 *
 *******************************************************************
 * Changes:
 *     Date         Changed by      Description
 *     ----         ----------      -----------
 *
 *******************************************************************/

#ifndef FILELINESPROVIDER_H
#define FILELINESPROVIDER_H


class SerialInterface;

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

#endif // FILELINESPROVIDER_H
