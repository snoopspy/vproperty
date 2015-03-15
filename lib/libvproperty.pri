include(../../../qt/qt-solutions/qtpropertybrowser/src/qtpropertybrowser.pri)

CONFIG += VPROPERTY_BUILD
include(../vproperty.pri)

SOURCES += \
	$${PWD}/../src/property/vproperty.cpp \
	$${PWD}/../src/property/vpropertywidget.cpp \
	$${PWD}/../src/property/vpropertywidgetprivate.cpp

HEADERS += \
	$${PWD}/../src/property/vproperty.h \
	$${PWD}/../src/property/vpropertywidget.h \
	$${PWD}/../src/property/vpropertywidgetprivate.h
