QT += core gui widgets

include(../../../../../google/gtest/gtest.pri)
include(../../../lib/libvproperty.pri)

#QMAKE_CXXFLAGS += -std=c++11

TARGET = vproperty_test
TEMPLATE = app
DESTDIR = $$PWD/../../../bin

SOURCES += main.cpp \
    ip.cpp \
    netclient.cpp \
    myobj.cpp

HEADERS += \
    ip.h \
    netclient.h \
    myobj.h
