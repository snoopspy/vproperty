// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_ITEM_QCHAR_H__
#define __V_PROPERTY_WIDGET_ITEM_QCHAR_H__

#include "vpropertyitem_base.h"

// ----------------------------------------------------------------------------
// VPropertyItem_QChar
// ----------------------------------------------------------------------------
class VPropertyItem_QChar : public VPropertyItem_Base
{
  Q_OBJECT
public:
  VPropertyItem_QChar(VPropertyItemParam param) : VPropertyItem_Base(param)
  {
  }

protected slots:
  void myEditingFinished() override
  {
    QChar value;
    QString text = lineEdit->text();
    if (text.length() == 0) value = '\0';
    else value = text.at(0);
    object->setProperty(mpro.name(), value);
    update();
  }
};

// ----------------------------------------------------------------------------
// VPropertyItemCreator_QChar
// ----------------------------------------------------------------------------
class VPropertyItemCreator_QChar : public VPropertyItemCreator
{
public:
  VPropertyItem* createItem(VPropertyItemParam param) override
  {
    if (param.mpro.userType() != QMetaType::QChar) return nullptr;
    return new VPropertyItem_QChar(param);
  }
};

#endif // __V_PROPERTY_WIDGET_ITEM_QCHAR_H__
