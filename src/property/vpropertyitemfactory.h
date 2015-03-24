// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_ITEM_FACTORY_H__
#define __V_PROPERTY_WIDGET_ITEM_FACTORY_H__

#include <QList>
#include "vpropertyitemcreator.h"

// ----------------------------------------------------------------------------
// VPropertyItemFactory
// ----------------------------------------------------------------------------
class VPropertyItemFactory : public QList<VPropertyItemCreator*>
{
public:
  VPropertyItem* createItem(VPropertyItemParam param);
  static VPropertyItemFactory& instance();
};

#endif // __V_PROPERTY_WIDGET_ITEM_FACTORY_H__
