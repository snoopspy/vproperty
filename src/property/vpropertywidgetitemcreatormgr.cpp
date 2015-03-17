#include "vpropertywidgetitemcreatormgr.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetItemCreatorMgr
// ----------------------------------------------------------------------------
VPropertyWidgetItemCreatorMgr& VPropertyWidgetItemCreatorMgr::instance()
{
  static VPropertyWidgetItemCreatorMgr mgr;
  return mgr;
}
