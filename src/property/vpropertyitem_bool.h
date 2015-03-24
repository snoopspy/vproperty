// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_ITEM_BOOL_H__
#define __V_PROPERTY_WIDGET_ITEM_BOOL_H__

#include <QCheckBox>
#include "vpropertyitemcreator.h"

// ----------------------------------------------------------------------------
// VPropertyItem_Bool
// ----------------------------------------------------------------------------
class VPropertyItem_Bool : public VPropertyItem
{
  Q_OBJECT

public:
  VPropertyItem_Bool(VPropertyItemParam param) : VPropertyItem(param)
  {
    checkBox = new QCheckBox(param.treeWidget);
    QObject::connect(checkBox, SIGNAL(clicked(bool)), this, SLOT(myClicked(bool)));
    param.treeWidget->setItemWidget(this, 1, checkBox);
  }

  void update() override
  {
    checkBox->setChecked(object->property(mpro.name()).toBool());
  }

protected:
  QCheckBox* checkBox;

protected slots:
  void myClicked(bool checked)
  {
    object->setProperty(mpro.name(), checked);
    update();
  }
};

// ----------------------------------------------------------------------------
// VPropertyItemCreator_Bool
// ----------------------------------------------------------------------------
class VPropertyItemCreator_Bool : public VPropertyItemCreator
{
public:
  VPropertyItem* createItem(VPropertyItemParam param) override
  {
    if (param.mpro.userType() != QMetaType::Bool) return nullptr;
    return new VPropertyItem_Bool(param);
  }
};

#endif // __V_PROPERTY_WIDGET_ITEM_BOOL_H__
