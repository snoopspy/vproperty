#include "vpropertywidgetcreatormgr.h"
#include "vpropertywidgetcreatorlineedit.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetCreatorMgrInstance
// ----------------------------------------------------------------------------
class VPropertyWidgetCreatorMgrInstance : public VPropertyWidgetCreatorMgr
{
public:
  VPropertyWidgetCreatorMgrInstance()
  {
    VPropertyWidgetCreatorLineEdit* intCreator = new VPropertyWidgetCreatorLineEdit(QMetaType::Int);
    this->append(intCreator);

    VPropertyWidgetCreatorLineEdit* stringCreator = new VPropertyWidgetCreatorLineEdit(QMetaType::QString);
    append(stringCreator);
  }
  virtual ~VPropertyWidgetCreatorMgrInstance()
  {
    // memory leak // gilgil temp 2105.03.18
  }
};

// ----------------------------------------------------------------------------
// VPropertyWidgetCreatorMgr
// ----------------------------------------------------------------------------
VPropertyWidgetCreatorMgr& VPropertyWidgetCreatorMgr::instance()
{
  static VPropertyWidgetCreatorMgrInstance mgr;
  return mgr;
}
