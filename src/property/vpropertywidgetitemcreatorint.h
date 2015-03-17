// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_ITEM_CREATOR_INT_H__
#define __V_PROPERTY_WIDGET_ITEM_CREATOR_INT_H__

#include "vpropertywidgetitemcreator.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetItemCreatorInt
// ----------------------------------------------------------------------------
class VPropertyWidgetItemCreatorInt : public VPropertyWidgetItemCreator
{
  virtual VPropertyWidgetItem* createPropertyWidgetItem(QMetaProperty mpro);
};

#endif // __V_PROPERTY_WIDGET_ITEM_CREATOR_INT_H__
