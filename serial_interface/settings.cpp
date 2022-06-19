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
void Settings::setUIntValue(QString key, unsigned int value) {
    //--
}

void Settings::setIntValue(QString key, int value) {
    //--
}

void Settings::setFloatValue(QString key, float value) {
    //--
}

void Settings::setDoubleValue(QString key, double value) {
    //--
}

void Settings::setQStringValue(QString key, QString value) {
    //--
}

//------------------
// Getters
//---------------
unsigned int Settings::getUIntValue(QString key) {
    //--
    return 0;
}

int Settings::getIntValue(QString key) {
    //--
    return 0;
}

float Settings::getFloatValue(QString key) {
    //--
    return 0;
}

double Settings::getDoubleValue(QString key) {
    //--
    return 0;
}

QString Settings::getQStringValue(QString key) {
    //--
    return "";
}
