QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# For disabling debugging messages set this value to 0 - 1 otherwise
DEFINES += _DEBUGGING_MESSAGES=1

SOURCES += \
    serial_interface/file_lines_provider.cpp \
    serial_interface/port_communicator.cpp \
    serial_interface/port_discoverer.cpp \
    serial_interface/serial_interface.cpp \
    serial_interface/settings.cpp \
    main.cpp \
    main_window.cpp

HEADERS += \
    serial_interface/file_lines_provider.h \
    serial_interface/macros.h \
    serial_interface/port_communicator.h \
    serial_interface/port_discoverer.h \
    serial_interface/serial_interface.h \
    serial_interface/serial_types.h \
    serial_interface/settings.h \
    main_window.h

FORMS += \
    main_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
