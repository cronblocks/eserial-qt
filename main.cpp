/*******************************************************************
 * Purpose:
 *     The main entry-point for application startup.
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

#include "main_window.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    MainWindow main_window;
    main_window.show();

    return application.exec();
}
