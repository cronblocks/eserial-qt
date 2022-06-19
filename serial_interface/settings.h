#ifndef SETTINGS_H
#define SETTINGS_H


#include <QMap>
#include <qstring.h>


class Settings {

public:
    Settings(QString filename);

private:
    void loadSettings();

public:
    void saveSettings();

    void setUIntValue(QString key, unsigned int value);
    void setIntValue(QString key, int value);
    void setFloatValue(QString key, float value);
    void setDoubleValue(QString key, double value);
    void setQStringValue(QString key, QString value);

    unsigned int getUIntValue(QString key);
    int getIntValue(QString key);
    float getFloatValue(QString key);
    double getDoubleValue(QString key);
    QString getQStringValue(QString key);

private:
    QString m_filename;
    QMap<QString, QString> m_settings;
};

#endif // SETTINGS_H
