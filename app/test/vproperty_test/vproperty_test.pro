QT += core gui widgets

include(../../../lib/libvproperty.pri)
include(../../../../vdream/vdream.pri)

TARGET = vproperty_test
TEMPLATE = app
DESTDIR = $${PWD}/../../../bin

SOURCES += main.cpp \
    ip.cpp \
    netclient.cpp

HEADERS += \
    ip.h \
    netclient.h
