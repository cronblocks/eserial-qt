/*******************************************************************
 * Purpose:
 *     Reading and writing settings as key-value pairs.
 *
 *******************************************************************
 * Author: Usama
 *
 *******************************************************************
 * Changes:
 *     Date         Changed by      Description
 *     ----         ----------      -----------
 *
 *******************************************************************/

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

    void setUIntValue(const QString& key, unsigned int value);
    void setIntValue(const QString& key, int value);
    void setFloatValue(const QString& key, float value);
    void setDoubleValue(const QString& key, double value);
    void setQStringValue(const QString& key, QString&& value);

    unsigned int getUIntValue(const QString& key, unsigned int default_value = 0);
    int getIntValue(const QString& key, int default_value = 0);
    float getFloatValue(const QString& key, float default_value = 0);
    double getDoubleValue(const QString& key, double default_value = 0);
    QString getQStringValue(const QString& key, const QString& default_value = "");

private:
    QString m_filename;
    QMap<QString, QString> m_settings;
};

#endif // SETTINGS_H
