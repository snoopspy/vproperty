#include(../../../qt/qt-solutions/qtpropertybrowser/src/qtpropertybrowser.pri) # gilgil temp 2015.03.17

CONFIG += VPROPERTY_BUILD
include(../vproperty.pri)

HEADERS += \
    $$PWD/../src/property/vproperty.h \
    $$PWD/../src/property/vpropertyeditor.h \
    $$PWD/../src/property/vpropertyitem.h \
    $$PWD/../src/property/vpropertyitemcreator.h \
    $$PWD/../src/property/vpropertyitemcreatorcheckbox.h \
    $$PWD/../src/property/vpropertyitemcreatorlineedit.h \
    $$PWD/../src/property/vpropertyitemfactory.h

SOURCES += \
    $$PWD/../src/property/vproperty.cpp \
    $$PWD/../src/property/vpropertyeditor.cpp \
    $$PWD/../src/property/vpropertyitem.cpp \
    $$PWD/../src/property/vpropertyitemcreator.cpp \
    $$PWD/../src/property/vpropertyitemcreatorcheckbox.cpp \
    $$PWD/../src/property/vpropertyitemcreatorlineedit.cpp \
    $$PWD/../src/property/vpropertyitemfactory.cpp
