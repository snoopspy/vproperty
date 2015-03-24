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
  VPropertyItem_UnknownType(VPropertyEditor* editor, QObject* object, QMetaProperty mpro) : VPropertyItem(editor, object, mpro)
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
  VPropertyItem* createItem(VPropertyEditor* editor, QObject* object, QMetaProperty mpro) override
  {
    return new VPropertyItem_UnknownType(editor, object, mpro);
  }
};

#endif // __V_PROPERTY_WIDGET_ITEM_UNKNOWN_TYPE_H__
