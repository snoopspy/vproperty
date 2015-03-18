// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_ITEM_CREATOR_H__
#define __V_PROPERTY_WIDGET_ITEM_CREATOR_H__

#include <QMetaProperty>
#include "vpropertywidget.h"
#include "vpropertywidgetitem.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetItemCreator
// ----------------------------------------------------------------------------
class VPropertyWidgetItemCreator
{
public:
  virtual VPropertyWidgetItem* createPropertyWidgetItem(VPropertyWidget* widget, QObject* object, QMetaProperty mpro) = 0;
};

#endif // __V_PROPERTY_WIDGET_ITEM_CREATOR_H__
