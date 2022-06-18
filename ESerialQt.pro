QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SerialInterface/port_communicator.cpp \
    SerialInterface/port_discoverer.cpp \
    SerialInterface/serial_interface.cpp \
    SerialInterface/settings.cpp \
    main.cpp \
    main_window.cpp

HEADERS += \
    SerialInterface/port_communicator.h \
    SerialInterface/port_discoverer.h \
    SerialInterface/serial_interface.h \
    SerialInterface/settings.h \
    main_window.h

FORMS += \
    main_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
