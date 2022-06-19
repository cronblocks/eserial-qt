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
    std::unique_ptr<QFile> file = std::make_unique<QFile>(m_filename);

    DEBUG_MSG("Loading settings file: ");
    DEBUG_MSG(m_filename.toStdString());

    if (file->exists()) {

        DEBUG_MSG_LINE(" ... exists");

    } else {

        DEBUG_MSG_LINE(" ... doesnot exist");

    }
}

void Settings::saveSettings() {
    DEBUG_MSG("Saving settings file: ");
    DEBUG_MSG_LINE(m_filename.toStdString());
}

//------------------
// Setters
//---------------
void Settings::setUIntValue(const QString& key, unsigned int value) {
    //--
}

void Settings::setIntValue(const QString& key, int value) {
    //--
}

void Settings::setFloatValue(const QString& key, float value) {
    //--
}

void Settings::setDoubleValue(const QString& key, double value) {
    //--
}

void Settings::setQStringValue(const QString& key, QString&& value) {
    //--
}

//------------------
// Getters
//---------------
unsigned int Settings::getUIntValue(const QString& key, unsigned int default_value) {
    //--
    return default_value;
}

int Settings::getIntValue(const QString& key, int default_value) {
    //--
    return default_value;
}

float Settings::getFloatValue(const QString& key, float default_value) {
    //--
    return default_value;
}

double Settings::getDoubleValue(const QString& key, double default_value) {
    //--
    return default_value;
}

QString Settings::getQStringValue(const QString& key, const QString& default_value) {
    if (m_settings.contains(key)) {
        return m_settings[key];
    }

    return default_value;
}
