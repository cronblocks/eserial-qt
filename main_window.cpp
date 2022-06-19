#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);

    m_serial = std::make_unique<SerialInterface>();

    setUiBaudRate       ( m_serial->getBaudRate()       );
    setUiDataBits       ( m_serial->getDataBits()       );
    setUiParity         ( m_serial->getParity()         );
    setUiStopBits       ( m_serial->getStopBits()       );
    setUiLineEnding     ( m_serial->getLineEnding()     );
    setUiInterlinedelay ( m_serial->getInterlineDelay() );

    setupUiBaudRateReceiver();
    setupUiDataBitsReceiver();
    setupUiParityReceiver();
    setupUiStopBitsReceiver();
    setupUiLineEndingReceiver();
    setupUiInterlineDelayReceiver();

    m_serial->startInterface();
}

MainWindow::~MainWindow() {
    delete ui;
}

// -------------------------------
// Setting-up Events
// ----------------------------
void MainWindow::setupUiBaudRateReceiver() {
    connect(ui->actionBaudRate_300,    &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_600,    &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_1200,   &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_1800,   &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_2400,   &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_4800,   &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_7200,   &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_9600,   &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_14400,  &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_19200,  &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_28800,  &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_38400,  &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_57600,  &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_115200, &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_230400, &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_460800, &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_921600, &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_1M,     &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
    connect(ui->actionBaudRate_2M,     &QAction::triggered, this, &MainWindow::actionTriggeredUiBaudRateReceiver);
}

void MainWindow::setupUiDataBitsReceiver() {
    connect(ui->actionDataBits_5, &QAction::triggered, this, &MainWindow::actionTriggeredUiDataBitsReceiver);
    connect(ui->actionDataBits_6, &QAction::triggered, this, &MainWindow::actionTriggeredUiDataBitsReceiver);
    connect(ui->actionDataBits_7, &QAction::triggered, this, &MainWindow::actionTriggeredUiDataBitsReceiver);
    connect(ui->actionDataBits_8, &QAction::triggered, this, &MainWindow::actionTriggeredUiDataBitsReceiver);
}

void MainWindow::setupUiParityReceiver() {
    connect(ui->actionParity_None, &QAction::triggered, this, &MainWindow::actionTriggeredUiParityReceiver);
    connect(ui->actionParity_Even, &QAction::triggered, this, &MainWindow::actionTriggeredUiParityReceiver);
    connect(ui->actionParity_Odd,  &QAction::triggered, this, &MainWindow::actionTriggeredUiParityReceiver);
}

void MainWindow::setupUiStopBitsReceiver() {
    connect(ui->actionStopBits_1,   &QAction::triggered, this, &MainWindow::actionTriggeredUiStopBitsReceiver);
    connect(ui->actionStopBits_1_5, &QAction::triggered, this, &MainWindow::actionTriggeredUiStopBitsReceiver);
    connect(ui->actionStopBits_2,   &QAction::triggered, this, &MainWindow::actionTriggeredUiStopBitsReceiver);
}

void MainWindow::setupUiLineEndingReceiver() {
    connect(ui->actionLineEnding_None, &QAction::triggered, this, &MainWindow::actionTriggeredUiLineEndingReceiver);
    connect(ui->actionLineEnding_CR,   &QAction::triggered, this, &MainWindow::actionTriggeredUiLineEndingReceiver);
    connect(ui->actionLineEnding_LF,   &QAction::triggered, this, &MainWindow::actionTriggeredUiLineEndingReceiver);
    connect(ui->actionLineEnding_CRLF, &QAction::triggered, this, &MainWindow::actionTriggeredUiLineEndingReceiver);
}

void MainWindow::setupUiInterlineDelayReceiver() {
    connect(ui->actionInterlineDelay_1ms,    &QAction::triggered, this, &MainWindow::actionTriggeredUiInterlineDelayReceiver);
    connect(ui->actionInterlineDelay_5ms,    &QAction::triggered, this, &MainWindow::actionTriggeredUiInterlineDelayReceiver);
    connect(ui->actionInterlineDelay_10ms,   &QAction::triggered, this, &MainWindow::actionTriggeredUiInterlineDelayReceiver);
    connect(ui->actionInterlineDelay_20ms,   &QAction::triggered, this, &MainWindow::actionTriggeredUiInterlineDelayReceiver);
    connect(ui->actionInterlineDelay_50ms,   &QAction::triggered, this, &MainWindow::actionTriggeredUiInterlineDelayReceiver);
    connect(ui->actionInterlineDelay_100ms,  &QAction::triggered, this, &MainWindow::actionTriggeredUiInterlineDelayReceiver);
    connect(ui->actionInterlineDelay_200ms,  &QAction::triggered, this, &MainWindow::actionTriggeredUiInterlineDelayReceiver);
    connect(ui->actionInterlineDelay_500ms,  &QAction::triggered, this, &MainWindow::actionTriggeredUiInterlineDelayReceiver);
    connect(ui->actionInterlineDelay_1sec,   &QAction::triggered, this, &MainWindow::actionTriggeredUiInterlineDelayReceiver);
    connect(ui->actionInterlineDelay_2sec,   &QAction::triggered, this, &MainWindow::actionTriggeredUiInterlineDelayReceiver);
    connect(ui->actionInterlineDelay_Custom, &QAction::triggered, this, &MainWindow::actionTriggeredUiInterlineDelayReceiver);
}

// -------------------------------
// Handling Events
// ----------------------------
void MainWindow::closeEvent(QCloseEvent *) {
    m_serial->stopInterface();
}

void MainWindow::actionTriggeredUiBaudRateReceiver(bool checked) {
    QAction *action = (QAction *)sender();
    BaudRate baud_rate = static_cast<BaudRate>(action->text().remove(',').remove(' ').toInt());

    if (checked) {
        m_serial->setBaudRate(baud_rate);
    }

    setUiBaudRate(m_serial->getBaudRate());
}

void MainWindow::actionTriggeredUiDataBitsReceiver(bool checked) {
    QAction *action = (QAction *)sender();
    DataBits data_bits = static_cast<DataBits>(action->text().remove(',').remove(' ').toInt());

    if (checked) {
        m_serial->setDataBits(data_bits);
    }

    setUiDataBits(m_serial->getDataBits());
}

void MainWindow::actionTriggeredUiParityReceiver(bool checked) {
    QAction *action = (QAction *)sender();
    QString parity_str = action->text().trimmed().remove(' ').toLower();

    if (checked) {
        if (parity_str == "none") {
            m_serial->setParity(Parity::None);
        } else if (parity_str == "even") {
            m_serial->setParity(Parity::Even);
        } else if (parity_str == "odd") {
            m_serial->setParity(Parity::Odd);
        }
    }

    setUiParity(m_serial->getParity());
}

void MainWindow::actionTriggeredUiStopBitsReceiver(bool checked) {
    QAction *action = (QAction *)sender();
    float stop_bits = action->text().trimmed().remove(' ').toFloat();

    if (checked) {
        if (stop_bits == 1) {
            m_serial->setStopBits(StopBits::One);
        } else if (stop_bits == 1.5) {
            m_serial->setStopBits(StopBits::OnePtFive);
        } else if (stop_bits == 2) {
            m_serial->setStopBits(StopBits::Two);
        }
    }

    setUiStopBits(m_serial->getStopBits());
}

void MainWindow::actionTriggeredUiLineEndingReceiver(bool checked) {
    QAction *action = (QAction *)sender();
    QString line_ending = action->text().remove(QRegularExpression(" .*$")).trimmed().toLower();

    if (checked) {
        if (line_ending == "none") {
            m_serial->setLineEnding(LineEnding::None);
        } else if (line_ending == "cr") {
            m_serial->setLineEnding(LineEnding::CR);
        } else if (line_ending == "lf") {
            m_serial->setLineEnding(LineEnding::LF);
        } else if (line_ending == "crlf") {
            m_serial->setLineEnding(LineEnding::CRLF);
        }
    }

    setUiLineEnding(m_serial->getLineEnding());
}

void MainWindow::actionTriggeredUiInterlineDelayReceiver(bool checked) {
    //--
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
    ui->actionLineEnding_None->setChecked(line_ending == LineEnding::None);
    ui->actionLineEnding_CR->setChecked(line_ending == LineEnding::CR);
    ui->actionLineEnding_LF->setChecked(line_ending == LineEnding::LF);
    ui->actionLineEnding_CRLF->setChecked(line_ending == LineEnding::CRLF);
}

void MainWindow::setUiInterlinedelay(unsigned int delay_ms) {

    if ( delay_ms == 1    ||
         delay_ms == 5    ||
         delay_ms == 10   ||
         delay_ms == 20   ||
         delay_ms == 50   ||
         delay_ms == 100  ||
         delay_ms == 200  ||
         delay_ms == 500  ||
         delay_ms == 1000 ||
         delay_ms == 2000 ) {

        ui->actionInterlineDelay_1ms->setChecked(delay_ms == 1);
        ui->actionInterlineDelay_5ms->setChecked(delay_ms == 5);

        ui->actionInterlineDelay_10ms->setChecked(delay_ms == 10);
        ui->actionInterlineDelay_20ms->setChecked(delay_ms == 20);
        ui->actionInterlineDelay_50ms->setChecked(delay_ms == 50);

        ui->actionInterlineDelay_100ms->setChecked(delay_ms == 100);
        ui->actionInterlineDelay_200ms->setChecked(delay_ms == 200);
        ui->actionInterlineDelay_500ms->setChecked(delay_ms == 500);

        ui->actionInterlineDelay_1sec->setChecked(delay_ms == 1000);
        ui->actionInterlineDelay_2sec->setChecked(delay_ms == 2000);

        ui->actionInterlineDelay_Custom->setChecked(false);

    } else {

        ui->actionInterlineDelay_1ms->setChecked(false);
        ui->actionInterlineDelay_5ms->setChecked(false);

        ui->actionInterlineDelay_10ms->setChecked(false);
        ui->actionInterlineDelay_20ms->setChecked(false);
        ui->actionInterlineDelay_50ms->setChecked(false);

        ui->actionInterlineDelay_100ms->setChecked(false);
        ui->actionInterlineDelay_200ms->setChecked(false);
        ui->actionInterlineDelay_500ms->setChecked(false);

        ui->actionInterlineDelay_1sec->setChecked(false);
        ui->actionInterlineDelay_2sec->setChecked(false);

        ui->actionInterlineDelay_Custom->setChecked(true);

    }
}
