/*******************************************************************
 * Purpose:
 *     Reading and writing settings as key-value pairs
 *
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

#include "settings.h"

#include "macros.h"

#include <QFile>
#include <QTextStream>

#include <iostream>
#include <memory>

Settings::Settings(QString filename) {
    m_filename = filename;
    m_settings.clear();

    loadSettings();
}

void Settings::loadSettings() {
    DEBUG_MSG("Loading settings file: ");
    DEBUG_MSG(m_filename.toStdString());

    QFile file = QFile(m_filename);

    if (file.exists()) {

        DEBUG_MSG_LINE(" ... exists");

        if (file.open(QIODevice::ReadOnly)) {
            QTextStream stream = QTextStream(&file);

            while (!stream.atEnd()) {
                QString line = stream.readLine();

                if (line.contains('=')) {
                    QStringList parts = line.split('=');

                    if (parts.count() == 2) {
                        setQStringValue(
                                    parts.value(0).trimmed(),
                                    parts.value(1).trimmed());
                    }
                }
            }

            file.close();
        }

    } else {

        DEBUG_MSG_LINE(" ... doesnot exist");

    }
}

void Settings::saveSettings() {
    DEBUG_MSG("Saving settings file: ");
    DEBUG_MSG_LINE(m_filename.toStdString());

    QFile file = QFile(m_filename);

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream = QTextStream(&file);

        QMapIterator<QString, QString> iterator(m_settings);

        while (iterator.hasNext()) {
            iterator.next();
            stream << iterator.key() << " = " << iterator.value() << Qt::endl;
        }

        stream.flush();
        file.close();
    }
}

//------------------
// Setters
//---------------
void Settings::setUIntValue(const QString& key, unsigned int value) {
    if (m_settings.contains(key)) {
        m_settings.remove(key);
    }

    m_settings.insert(key, QString::number(value));
}

void Settings::setIntValue(const QString& key, int value) {
    if (m_settings.contains(key)) {
        m_settings.remove(key);
    }

    m_settings.insert(key, QString::number(value));
}

void Settings::setFloatValue(const QString& key, float value) {
    if (m_settings.contains(key)) {
        m_settings.remove(key);
    }

    m_settings.insert(key, QString::number(value));
}

void Settings::setDoubleValue(const QString& key, double value) {
    if (m_settings.contains(key)) {
        m_settings.remove(key);
    }

    m_settings.insert(key, QString::number(value));
}

void Settings::setQStringValue(const QString& key, QString&& value) {
    if (m_settings.contains(key)) {
        m_settings.remove(key);
    }

    m_settings.insert(key, value);
}

//------------------
// Getters
//---------------
unsigned int Settings::getUIntValue(const QString& key, unsigned int default_value) {
    bool is_ok;
    unsigned int return_value;

    if (m_settings.contains(key)) {
        return_value = m_settings[key].toUInt(&is_ok);
        if (is_ok) return return_value;
    }

    return default_value;
}

int Settings::getIntValue(const QString& key, int default_value) {
    bool is_ok;
    int return_value;

    if (m_settings.contains(key)) {
        return_value = m_settings[key].toInt(&is_ok);
        if (is_ok) return return_value;
    }

    return default_value;
}

float Settings::getFloatValue(const QString& key, float default_value) {
    bool is_ok;
    float return_value;

    if (m_settings.contains(key)) {
        return_value = m_settings[key].toFloat(&is_ok);
        if (is_ok) return return_value;
    }

    return default_value;
}

double Settings::getDoubleValue(const QString& key, double default_value) {
    bool is_ok;
    double return_value;

    if (m_settings.contains(key)) {
        return_value = m_settings[key].toDouble(&is_ok);
        if (is_ok) return return_value;
    }

    return default_value;
}

QString Settings::getQStringValue(const QString& key, const QString& default_value) {
    if (m_settings.contains(key)) {
        return QString(m_settings[key]);
    }

    return default_value;
}
