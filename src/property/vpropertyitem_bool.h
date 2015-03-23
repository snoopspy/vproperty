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
  VPropertyItem_Bool(VPropertyEditor* editor, QObject* object, QMetaProperty mpro) : VPropertyItem(editor, object, mpro)
  {
    checkBox = new QCheckBox(editor);
    checkBox->setChecked(object->property(mpro.name()).toBool());
    QObject::connect(checkBox, SIGNAL(clicked(bool)), this, SLOT(myClicked(bool)));
    editor->setItemWidget(this, 1, checkBox);
  }

protected:
  QCheckBox* checkBox;

protected slots:
  void myClicked(bool checked)
  {
    object->setProperty(mpro.name(), checked);
  }
};

// ----------------------------------------------------------------------------
// VPropertyItemCreator_Bool
// ----------------------------------------------------------------------------
class VPropertyItemCreator_Bool : public VPropertyItemCreator
{
public:
  VPropertyItem* createItem(VPropertyEditor* editor, QObject* object, QMetaProperty mpro) override
  {
    if (mpro.userType() != QMetaType::Bool) return nullptr;
    return new VPropertyItem_Bool(editor, object, mpro);
  }
};

#endif // __V_PROPERTY_WIDGET_ITEM_BOOL_H__
