#include(../../../qt/qt-solutions/qtpropertybrowser/src/qtpropertybrowser.pri) # gilgil temp 2015.03.17

CONFIG += VPROPERTY_BUILD
include(../vproperty.pri)

HEADERS += \
    $$PWD/../src/property/vproperty.h \
    $$PWD/../src/property/vpropertywidget.h \
    $$PWD/../src/property/vpropertywidgetitem.h \
    $$PWD/../src/property/vpropertywidgetitemcreator.h \
    $$PWD/../src/property/vpropertywidgetitemcreatorlineedit.h \
    $$PWD/../src/property/vpropertywidgetitemcreatormgr.h

SOURCES += \
    $$PWD/../src/property/vproperty.cpp \
    $$PWD/../src/property/vpropertywidget.cpp \
    $$PWD/../src/property/vpropertywidgetitem.cpp \
    $$PWD/../src/property/vpropertywidgetitemcreator.cpp \
    $$PWD/../src/property/vpropertywidgetitemcreatormgr.cpp \
    $$PWD/../src/property/vpropertywidgetitemcreatorlineedit.cpp

