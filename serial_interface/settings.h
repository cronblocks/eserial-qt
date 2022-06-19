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

    unsigned int getUIntValue(QString key, unsigned int default_value = 0);
    int getIntValue(QString key, int default_value = 0);
    float getFloatValue(QString key, float default_value = 0);
    double getDoubleValue(QString key, double default_value = 0);
    QString getQStringValue(QString key, const QString& default_value = "");

private:
    QString m_filename;
    QMap<QString, QString> m_settings;
};

#endif // SETTINGS_H
