// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_ITEM_CREATOR_MGR_H__
#define __V_PROPERTY_WIDGET_ITEM_CREATOR_MGR_H__

#include <QList>
#include "vpropertywidgetitemcreator.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetItemCreatorMgr
// ----------------------------------------------------------------------------
class VPropertyWidgetItemCreatorMgr : QList<VPropertyWidgetItemCreator*>
{
public:
  static VPropertyWidgetItemCreatorMgr& instance();
};

#endif // __V_PROPERTY_WIDGET_ITEM_CREATOR_MGR_H__
