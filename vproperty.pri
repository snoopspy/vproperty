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
CONFIG(GTEST)                VPROPERTY_NAME = $${VPROPERTY_NAME}_test
CONFIG(debug, debug|release) VPROPERTY_NAME = $${VPROPERTY_NAME}_d

#------------------------------------------------------------------------------
# vproperty
#------------------------------------------------------------------------------
VPROPERTY_DIR = $$PWD
INCLUDEPATH += $$VPROPERTY_DIR/src
!CONFIG(VPROPERTY_BUILD) {
	PRE_TARGETDEPS +=  $$VPROPERTY_DIR/lib/lib$${VPROPERTY_NAME}.a
	LIBS           += -L$$VPROPERTY_DIR/lib -l$$VPROPERTY_NAME
}
