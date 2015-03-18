#include "vpropertywidgetitemcreatormgr.h"
#include "vpropertywidgetitemcreatorlineedit.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetItemCreatorMgrInstance
// ----------------------------------------------------------------------------
class VPropertyWidgetItemCreatorMgrInstance : public VPropertyWidgetItemCreatorMgr
{
public:
  VPropertyWidgetItemCreatorMgrInstance()
  {
    VPropertyWidgetItemCreatorLineEdit<QMetaType::Int>* intCreator = new VPropertyWidgetItemCreatorLineEdit<QMetaType::Int>;
    append(intCreator);

    VPropertyWidgetItemCreatorLineEdit<QMetaType::QString>* stringCreator = new VPropertyWidgetItemCreatorLineEdit<QMetaType::QString>;
    append(stringCreator);
  }
};

// ----------------------------------------------------------------------------
// VPropertyWidgetItemCreatorMgr
// ----------------------------------------------------------------------------
VPropertyWidgetItemCreatorMgr& VPropertyWidgetItemCreatorMgr::instance()
{
  static VPropertyWidgetItemCreatorMgrInstance mgr;

  return mgr;
}
