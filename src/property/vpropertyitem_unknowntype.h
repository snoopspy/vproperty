// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_ITEM_UNKNOWN_TYPE_H__
#define __V_PROPERTY_WIDGET_ITEM_UNKNOWN_TYPE_H__

#include <QCheckBox>
#include "vpropertyitemcreator.h"

// ----------------------------------------------------------------------------
// VPropertyItem_UnknownType
// ----------------------------------------------------------------------------
class VPropertyItem_UnknownType : public VPropertyItem
{
  Q_OBJECT

public:
  VPropertyItem_UnknownType(VPropertyItemParam param) : VPropertyItem(param)
  {
    this->setBackground(1, QBrush(Qt::lightGray));
  }

  void update() override
  {
  }
};

// ----------------------------------------------------------------------------
// VPropertyItemCreator_UnknownType
// ----------------------------------------------------------------------------
class VPropertyItemCreator_UnknownType : public VPropertyItemCreator
{
public:
  VPropertyItem* createItem(VPropertyItemParam param) override
  {
    return new VPropertyItem_UnknownType(param);
  }
};

#endif // __V_PROPERTY_WIDGET_ITEM_UNKNOWN_TYPE_H__
