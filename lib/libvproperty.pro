QT += gui widgets

CONFIG += VPROPERTY_BUILD
include(libvproperty.pri)

TARGET = $${VPROPERTY_NAME}
TEMPLATE = lib
CONFIG += staticlib
DESTDIR = $${PWD}
