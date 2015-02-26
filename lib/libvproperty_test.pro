QT += core
QT -= gui

include(../../../google/gtest/gtest.pri)
CONFIG += VPROPERTY_BUILD
include(../vproperty.pro)

TARGET = $${VPROPERTY_NAME}
TEMPLATE = lib
CONFIG += staticlib
DESTDIR = $${PWD}
