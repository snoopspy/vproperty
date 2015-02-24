#-------------------------------------------------
# debug and release
#-------------------------------------------------
CONFIG(debug,   debug|release) DEFINES += _DEBUG
CONFIG(release, debug|release) DEFINES += _RELEASE
message($${DEFINES}) # gilgil temp 2015.02.24

#-------------------------------------------------
# library name
#-------------------------------------------------
VPROPERTY_LIB_NAME = vproperty
android-g++:                 VPROPERTY_LIB_NAME = $${VPROPERTY_LIB_NAME}_android
CONFIG(debug, debug|release) VPROPERTY_LIB_NAME = $${VPROPERTY_LIB_NAME}_d
message($${VPROPERTY_LIB_NAME})  # gilgil temp 2015.02.24

#-------------------------------------------------
# vproperty
#-------------------------------------------------
VPROPERTY_PATH = $${PWD}
INCLUDEPATH += $${VPROPERTY_PATH}/src
!CONFIG(VPROPERTY_LIB_BUILD) {
  PRE_TARGETDEPS +=  $${VPROPERTY_PATH}/lib/lib$${VPROPERTY_LIB_NAME}.a
  LIBS           += -L$${VPROPERTY_PATH}/lib
  LIBS           += -l$${VPROPERTY_LIB_NAME}
}
