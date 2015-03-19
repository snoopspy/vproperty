#include(../../../qt/qt-solutions/qtpropertybrowser/src/qtpropertybrowser.pri) # gilgil temp 2015.03.17

CONFIG += VPROPERTY_BUILD
include(../vproperty.pri)

HEADERS += \
    $$PWD/../src/property/vproperty.h \
    $$PWD/../src/property/vpropertyeditor.h \
	$$PWD/../src/property/vpropertywidget.h \
	$$PWD/../src/property/vpropertywidgetcreator.h \
	$$PWD/../src/property/vpropertywidgetcreatorcheckbox.h \
	$$PWD/../src/property/vpropertywidgetcreatorlineedit.h \
	$$PWD/../src/property/vpropertywidgetfactory.h

SOURCES += \
    $$PWD/../src/property/vproperty.cpp \
    $$PWD/../src/property/vpropertyeditor.cpp \
	$$PWD/../src/property/vpropertywidget.cpp \
	$$PWD/../src/property/vpropertywidgetcreator.cpp \
	$$PWD/../src/property/vpropertywidgetcreatorcheckbox.cpp \
	$$PWD/../src/property/vpropertywidgetcreatorlineedit.cpp \
    $$PWD/../src/property/vpropertywidgetfactory.cpp
