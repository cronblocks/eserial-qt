#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);

    m_serial = std::make_unique<SerialInterface>();

    setUiBaudRate   ( m_serial->getBaudRate()   );
    setUiDataBits   ( m_serial->getDataBits()   );
    setUiParity     ( m_serial->getParity()     );
    setUiStopBits   ( m_serial->getStopBits()   );
    setUiLineEnding ( m_serial->getLineEnding() );

    m_serial->startInterface();
}

MainWindow::~MainWindow() {
    delete ui;
}

// -------------------------------
// Handling Events
// ----------------------------
void MainWindow::closeEvent(QCloseEvent *) {
    m_serial->stopInterface();
}

// -------------------------------
// Setting-up GUI Elements
// ----------------------------
void MainWindow::setUiBaudRate(BaudRate baud_rate) {
    ui->actionBaudRate_300->setChecked(baud_rate == BaudRate::_300);
    ui->actionBaudRate_600->setChecked(baud_rate == BaudRate::_600);

    ui->actionBaudRate_1200->setChecked(baud_rate == BaudRate::_1200);
    ui->actionBaudRate_1800->setChecked(baud_rate == BaudRate::_1800);
    ui->actionBaudRate_2400->setChecked(baud_rate == BaudRate::_2400);
    ui->actionBaudRate_4800->setChecked(baud_rate == BaudRate::_4800);
    ui->actionBaudRate_7200->setChecked(baud_rate == BaudRate::_7200);
    ui->actionBaudRate_9600->setChecked(baud_rate == BaudRate::_9600);

    ui->actionBaudRate_14400->setChecked(baud_rate == BaudRate::_14400);
    ui->actionBaudRate_19200->setChecked(baud_rate == BaudRate::_19200);
    ui->actionBaudRate_28800->setChecked(baud_rate == BaudRate::_28800);
    ui->actionBaudRate_38400->setChecked(baud_rate == BaudRate::_38400);
    ui->actionBaudRate_57600->setChecked(baud_rate == BaudRate::_57600);

    ui->actionBaudRate_115200->setChecked(baud_rate == BaudRate::_115200);
    ui->actionBaudRate_230400->setChecked(baud_rate == BaudRate::_230400);
    ui->actionBaudRate_460800->setChecked(baud_rate == BaudRate::_460800);
    ui->actionBaudRate_921600->setChecked(baud_rate == BaudRate::_921600);

    ui->actionBaudRate_1M->setChecked(baud_rate == BaudRate::_1000000);
    ui->actionBaudRate_2M->setChecked(baud_rate == BaudRate::_2000000);
}

void MainWindow::setUiDataBits(DataBits data_bits) {
    ui->actionDataBits_5->setChecked(data_bits == DataBits::_5);
    ui->actionDataBits_6->setChecked(data_bits == DataBits::_6);
    ui->actionDataBits_7->setChecked(data_bits == DataBits::_7);
    ui->actionDataBits_8->setChecked(data_bits == DataBits::_8);
}

void MainWindow::setUiParity(Parity parity) {
    ui->actionParity_None->setChecked(parity == Parity::None);
    ui->actionParity_Even->setChecked(parity == Parity::Even);
    ui->actionParity_Odd->setChecked(parity == Parity::Odd);
}

void MainWindow::setUiStopBits(StopBits stop_bits) {
    ui->actionStopBits_1->setChecked(stop_bits == StopBits::One);
    ui->actionStopBits_1_5->setChecked(stop_bits == StopBits::OnePtFive);
    ui->actionStopBits_2->setChecked(stop_bits == StopBits::Two);
}

void MainWindow::setUiLineEnding(LineEnding line_ending) {
    //--
}
