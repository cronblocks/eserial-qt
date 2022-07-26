/*******************************************************************
 * Purpose:
 *     Background events handling for Main Window
 *
 *
 *******************************************************************
 * Author: Usama
 *
 *******************************************************************
 * Changes:
 *
 *    Date              Description
 *    ----              -----------
 *
 *
 *
 *
 *******************************************************************/

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>

#include "serial_interface/serial_interface.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SerialInterface *m_serial;
    QString m_start_button_initial_text;
    QString m_start_button_stop_text;

    QFile *m_dump_file;
    QTextStream *m_dump_stream;

    void connectUiEventReceivers();
    void connectSerialPortSignals();

    void onUiSerialPortStartButtonClicked();
    void onUiTransmitTextSendButtonClicked();
    void onUiTransmitTextSendFileButtonClicked();
    void onUiReceiveTextClearButtonClicked();

    void onUiSerialPortComboBoxSelectionChanged();

    void onUiSendTextEditTextChanged();

    void onUiBaudRateActionTriggered(bool checked);
    void onUiDataBitsActionTriggered(bool checked);
    void onUiParityActionTriggered(bool checked);
    void onUiStopBitsActionTriggered(bool checked);
    void onUiLineEndingActionTriggered(bool checked);
    void onUiInterlineDelayActionTriggered(bool checked);

    void onSerialPortAdded(const QString&);
    void onSerialPortRemoved(const QString&);
    void onSerialPortOpened();
    void onSerialPortClosed();
    void onSerialPortFileTransmitPercentageUpdated(float);
    void onSerialPortDataReceived(const QString&);
    void onSerialPortErrorOccurred(const QString&);

    void setUiBaudRate(BaudRate);
    void setUiDataBits(DataBits);
    void setUiParity(Parity);
    void setUiStopBits(StopBits);
    void setUiLineEnding(LineEnding);
    void setUiInterlinedelay(unsigned int);
    void setUiForPortOpened();
    void setUiForPortClosed();

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *);
};
#endif // MAIN_WINDOW_H
