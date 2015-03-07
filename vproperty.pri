QT += core

#------------------------------------------------------------------------------
# debug and release
#------------------------------------------------------------------------------
CONFIG(debug, debug|release)   DEFINES += _DEBUG
CONFIG(release, debug|release) DEFINES += _RELEASE NDEBUG

#------------------------------------------------------------------------------
# library name
#------------------------------------------------------------------------------
VPROPERTY_NAME = vproperty
android-g++:                 VPROPERTY_NAME = $${VPROPERTY_NAME}_android
contains(QT, gui)            VPROPERTY_NAME = $${VPROPERTY_NAME}_gui
CONFIG(GTEST)                VPROPERTY_NAME = $${VPROPERTY_NAME}_test
CONFIG(debug, debug|release) VPROPERTY_NAME = $${VPROPERTY_NAME}_d

#------------------------------------------------------------------------------
# vproperty
#------------------------------------------------------------------------------
VPROPERTY_PATH = $${PWD}
INCLUDEPATH += $${VPROPERTY_PATH}/src
!CONFIG(VPROPERTY_BUILD) {
	PRE_TARGETDEPS +=  $${VPROPERTY_PATH}/lib/lib$${VPROPERTY_NAME}.a
	LIBS           += -L$${VPROPERTY_PATH}/lib -l$${VPROPERTY_NAME}
}
