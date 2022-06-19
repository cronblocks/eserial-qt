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

    std::unique_ptr<SerialInterface> m_serial;

    void setupUiBaudRateReceiver();
    void setupUiDataBitsReceiver();
    void setupUiParityReceiver();
    void setupUiStopBitsReceiver();
    void setupUiLineEndingReceiver();
    void setupUiInterlinedelayReceiver();

    void actionTriggeredUiBaudRateReceiver(bool checked);
    void actionTriggeredUiDataBitsReceiver(bool checked);
    void actionTriggeredUiParityReceiver(bool checked);
    void actionTriggeredUiStopBitsReceiver(bool checked);
    void actionTriggeredUiLineEndingReceiver(bool checked);
    void actionTriggeredUiInterlinedelayReceiver(bool checked);

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
