#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMap>
#include <QFile>
#include <qstring.h>

#include <memory>

class Settings {

public:
    Settings(QString filename);

private:
    void LoadSettings();

public:
    void SaveSettings();

    void SetUIntValue(QString key, unsigned int value);
    void SetIntValue(QString key, int value);
    void SetFloatValue(QString key, float value);
    void SetDoubleValue(QString key, double value);
    void SetQStringValue(QString key, QString value);

    unsigned int GetUIntValue(QString key);
    int GetIntValue(QString key);
    float GetFloatValue(QString key);
    double GetDoubleValue(QString key);
    QString GetQStringValue(QString key);

private:
    QString _filename;
    std::unique_ptr<QFile> _file;
    QMap<QString, QString> _settings;
};

#endif // SETTINGS_H
