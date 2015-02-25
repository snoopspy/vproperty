#------------------------------------------------------------------------------
# qtpropertybrowser
#------------------------------------------------------------------------------
include (../../qt/qt-solutions/qtpropertybrowser/src/qtpropertybrowser.pri)

#------------------------------------------------------------------------------
# vproperty
#------------------------------------------------------------------------------
VPROPERTY_PATH = $${PWD}
INCLUDEPATH += $${VPROPERTY_PATH}/src

SOURCES += \
	$${VPROPERTY_PATH}/src/property/vproperty.cpp \
	$${VPROPERTY_PATH}/src/property/vpropertywidget.cpp

HEADERS += \
	$${VPROPERTY_PATH}/src/property/vproperty.h \
	$${VPROPERTY_PATH}/src/property/vpropertywidget.h
