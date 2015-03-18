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
#include "vpropertyeditor.h"
#include "vpropertywidget.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetCreator
// ----------------------------------------------------------------------------
class VPropertyWidgetCreator
{
public:
  virtual VPropertyWidget* createPropertyWidgetItem(VPropertyEditor* editor, QObject* object, QMetaProperty mpro) = 0;
};

#endif // __V_PROPERTY_WIDGET_ITEM_CREATOR_H__
