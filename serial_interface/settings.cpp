#include "settings.h"

Settings::Settings(QString filename) {
    _filename = filename;

    LoadSettings();
}

void Settings::LoadSettings() {
    //--
}

void Settings::SaveSettings() {
    //--
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
