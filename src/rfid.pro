TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    RFIDMessage.cpp \
    SerialDevice.cpp \
    RFIDDevice.cpp

HEADERS += \
    RFIDMessage.h \
    RFIDCommandsCodes.h \
    RFIDattributeTypes.h \
    SerialDevice.h \
    RFIDDevice.h

