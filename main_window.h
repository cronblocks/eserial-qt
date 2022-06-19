#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <memory>
#include <QMainWindow>

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

    void connectUiEventReceivers();
    void connectSerialPortSignals();

    void onUiSerialPortStartButtonClicked();
    void onUiTransmitTextSendButtonClicked();
    void onUiTransmitTextSendFileButtonClicked();
    void onUiReceiveTextClearButtonClicked();

    void onUiSerialPortComboBoxSelectionChanged();

    void onUiBaudRateActionTriggered(bool checked);
    void onUiDataBitsActionTriggered(bool checked);
    void onUiParityActionTriggered(bool checked);
    void onUiStopBitsActionTriggered(bool checked);
    void onUiLineEndingActionTriggered(bool checked);
    void onUiInterlineDelayActionTriggered(bool checked);

    void onSerialPortAdded(const QString&);
    void onSerialPortRemoved(const QString&);
    void onSerialPortDataReceived(const QString&);
    void onSerialPortErrorOccurred(const QString&);

    void setUiBaudRate(BaudRate);
    void setUiDataBits(DataBits);
    void setUiParity(Parity);
    void setUiStopBits(StopBits);
    void setUiLineEnding(LineEnding);
    void setUiInterlinedelay(unsigned int);

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *);
};
#endif // MAIN_WINDOW_H
