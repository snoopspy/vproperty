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
#include "vpropertywidgetcreator.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetFactory
// ----------------------------------------------------------------------------
class VPropertyWidgetFactory : public QList<VPropertyWidgetCreator*>
{
public:
  VPropertyWidget* createWidget(VPropertyEditor* editor, QObject* object, QMetaProperty mpro);
  static VPropertyWidgetFactory& instance();
};

#endif // __V_PROPERTY_WIDGET_ITEM_CREATOR_MGR_H__
