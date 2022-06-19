#include "settings.h"

#include "macros.h"

#include <QFile>

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

    std::unique_ptr<QFile> file = std::make_unique<QFile>(m_filename);

    if (file->exists()) {

        DEBUG_MSG_LINE(" ... exists");

    } else {

        DEBUG_MSG_LINE(" ... doesnot exist");

    }
}

void Settings::saveSettings() {
    DEBUG_MSG("Saving settings file: ");
    DEBUG_MSG_LINE(m_filename.toStdString());

    std::unique_ptr<QFile> file = std::make_unique<QFile>(m_filename);
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
