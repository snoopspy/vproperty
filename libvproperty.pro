QT += core gui

include (../../qt/qt-solutions/qtpropertybrowser/src/qtpropertybrowser.pri)
CONFIG += VPROPERTY_LIB_BUILD
include (vproperty.pri)

TARGET = $${VPROPERTY_LIB_NAME}
TEMPLATE = lib
CONFIG += staticlib
DESTDIR = $${PWD}/lib

SOURCES += \
    src/property/vproperty.cpp

HEADERS += \
    src/property/vproperty.h
