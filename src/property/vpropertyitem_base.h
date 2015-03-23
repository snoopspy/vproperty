// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_ITEM_BASE_H__
#define __V_PROPERTY_WIDGET_ITEM_BASE_H__

#include <QLineEdit>
#include "vpropertyitemcreator.h"

// ----------------------------------------------------------------------------
// VPropertyItem_Base
// ----------------------------------------------------------------------------
class VPropertyItem_Base : public VPropertyItem
{
  Q_OBJECT

public:
  VPropertyItem_Base(VPropertyEditor* editor, QObject* object, QMetaProperty mpro) : VPropertyItem(editor, object, mpro)
  {
    lineEdit = new QLineEdit(editor);
    lineEdit->setFrame(false);
    lineEdit->setText(object->property(mpro.name()).toString());
    QObject::connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(myEditingFinished()));
    editor->setItemWidget(this, 1, lineEdit);
  }

protected:
  QLineEdit* lineEdit;

protected slots:
  void myEditingFinished()
  {
    object->setProperty(mpro.name(), QVariant::fromValue<QString>(lineEdit->text()));
  }
};

// ----------------------------------------------------------------------------
// VPropertyItemCreator_Base
// ----------------------------------------------------------------------------
class VPropertyItemCreator_Base : public VPropertyItemCreator
{
public:
  VPropertyItemCreator_Base(int userType)
  {
    this->userType = userType;
  }

  VPropertyItem* createItem(VPropertyEditor* editor, QObject* object, QMetaProperty mpro) override
  {
    if (mpro.userType() != userType) return nullptr;
    return new VPropertyItem_Base(editor, object, mpro);
  }

protected:
  int userType;
};

#endif // __V_PROPERTY_WIDGET_ITEM_BASE_H__
