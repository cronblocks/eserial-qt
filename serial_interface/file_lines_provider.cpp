#include "file_lines_provider.h"

#include "macros.h"

#include <QFile>
#include <QTextStream>


FileLinesProvider::FileLinesProvider(
        SerialInterface *serial_iface,
        const QString& filename) {

    m_serial_iface_ptr = serial_iface;
    m_filename = QString(filename);
    m_is_running = false;
}

void FileLinesProvider::startProvision() {
    if (!isRunning()) {
        start();
    }
}

void FileLinesProvider::stopProvision() {
    if (isRunning()) {
        m_is_running = false;
        wait();
    }
}

void FileLinesProvider::run() {

    int totalFileLines = countFileLines();
    int linesTransferred = 0;
    float transmissionPercentage = 0.f;

    if (totalFileLines <= 0) {
        emit errorOccurred(tr("Can't transmit %1 (total lines %2)")
                           .arg(m_filename)
                           .arg(totalFileLines));
    } else {
        emit provisionStarted();
        m_is_running = true;
    }

    while (m_is_running) {
        //--
        linesTransferred ++;
        transmissionPercentage = (linesTransferred * 1.0f) / totalFileLines;
        emit provisionPercentageUpdated(transmissionPercentage);
    }

    emit provisionCompleted();
}

int FileLinesProvider::countFileLines() {
    return -1;
}
