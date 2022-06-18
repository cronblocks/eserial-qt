#include "main_window.h"
#include "ui_main_window.h"
#include "serial_interface/serial_interface.h"

static SerialInterface serialInterface;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

