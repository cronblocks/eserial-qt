/*******************************************************************
 * Purpose:
 *     Providing text lines from given file for transmission over
 * Serial Port
 *
 *******************************************************************
 * Author: Usama
 *
 *******************************************************************
 * Changes:
 *
 * Date         Changed by      Description
 * ----         ----------      -----------
 *
 *
 *
 *
 *******************************************************************/

#include "file_lines_provider.h"

#include "macros.h"
#include "serial_interface.h"

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

    QFile *file = nullptr;
    QTextStream *stream = nullptr;

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
        if (file == nullptr) {
            file = new QFile(m_filename);

            if (file->open(QIODevice::ReadOnly)) {
                stream = new QTextStream(file);
            } else {
                emit errorOccurred(tr("Can't transmit %1 (total lines %2)")
                                   .arg(m_filename)
                                   .arg(totalFileLines));

                m_is_running = false;
                delete (file);
                delete (stream);
                file = nullptr;
                stream = nullptr;
                break;
            }
        } else {
            if (!stream->atEnd()) {
                m_serial_iface_ptr->sendTextLineToSerialPort(stream->readLine());
            } else {
                file->close();
                delete (file);
                delete (stream);
                file = nullptr;
                stream = nullptr;
                m_is_running = false;
            }

            linesTransferred ++;
            transmissionPercentage = (linesTransferred * 1.0f) / totalFileLines;
            emit provisionPercentageUpdated(transmissionPercentage);

            msleep(m_serial_iface_ptr->getInterlineDelay());
        }
    }

    emit provisionCompleted();
}

int FileLinesProvider::countFileLines() {
    QFile *file = nullptr;
    QTextStream *stream = nullptr;

    file = new QFile(m_filename);

    if (file->open(QIODevice::ReadOnly)) {
        stream = new QTextStream(file);

        int totalCount = 0;

        while (!stream->atEnd()) {
            stream->readLine();
            totalCount++;
        }

        file->close();
        delete (file);
        delete (stream);

        return totalCount;
    }

    return -1;
}
