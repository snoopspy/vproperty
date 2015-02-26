QT += core
QT -= gui

CONFIG += VPROPERTY_BUILD
include(../vproperty.pro)

TARGET = $${VPROPERTY_NAME}
TEMPLATE = lib
CONFIG += staticlib
DESTDIR = $${PWD}
