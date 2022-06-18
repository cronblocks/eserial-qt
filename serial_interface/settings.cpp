#include "settings.h"

#include "macros.h"

#include <iostream>

Settings::Settings(QString filename) {
    _filename = filename;
    _file = std::make_unique<QFile>(_filename);

    _uint_values.clear();
    _int_values.clear();
    _float_values.clear();
    _double_values.clear();
    _qstring_values.clear();

    LoadSettings();
}

void Settings::LoadSettings() {
    DEBUG_MSG("Loading settings file: ");
    DEBUG_MSG(_filename.toStdString());

    if (_file->exists()) {

        DEBUG_MSG_LINE(" ... exists");

    } else {

        DEBUG_MSG_LINE(" ... doesnot exist");

    }
}

void Settings::SaveSettings() {
    DEBUG_MSG("Saving settings file: ");
    DEBUG_MSG_LINE(_filename.toStdString());
}

//------------------
// Setters
//---------------
void Settings::SetUIntValue(QString key, unsigned int value) {
    //--
}

void Settings::SetIntValue(QString key, int value) {
    //--
}

void Settings::SetFloatValue(QString key, float value) {
    //--
}

void Settings::SetDoubleValue(QString key, double value) {
    //--
}

void Settings::SetQStringValue(QString key, QString value) {
    //--
}

//------------------
// Getters
//---------------
unsigned int Settings::GetUIntValue(QString key) {
    //--
    return 0;
}

int Settings::GetIntValue(QString key) {
    //--
    return 0;
}

float Settings::GetFloatValue(QString key) {
    //--
    return 0;
}

double Settings::GetDoubleValue(QString key) {
    //--
    return 0;
}

QString Settings::GetQStringValue(QString key) {
    //--
    return "";
}
