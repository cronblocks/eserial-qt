#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);

    serialInterface = std::make_unique<SerialInterface>();
    serialInterface->startInterface();
}

MainWindow::~MainWindow() {
    delete ui;
}

// -------------------------------
// Handling Events
// ----------------------------
void MainWindow::closeEvent(QCloseEvent *) {
    serialInterface->stopInterface();
}

