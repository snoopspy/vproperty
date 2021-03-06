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

#include <QDebug> // gilgil temp 2015.03.24
#include <QLineEdit>
#include "vpropertyitemcreator.h"

// ----------------------------------------------------------------------------
// VPropertyItem_Base
// ----------------------------------------------------------------------------
class VPropertyItem_Base : public VPropertyItem
{
  Q_OBJECT

public:
  VPropertyItem_Base(VPropertyItemParam param) : VPropertyItem(param)
  {
    lineEdit = new QLineEdit(param.treeWidget);
    lineEdit->setFrame(false);
    QObject::connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(myEditingFinished()));
    param.treeWidget->setItemWidget(this, 1, lineEdit);
  }

  void update() override
  {
    lineEdit->setText(object->property(mpro.name()).toString());
  }

protected:
  QLineEdit* lineEdit;

protected slots:
  virtual void myEditingFinished()
  {
    bool res = object->setProperty(mpro.name(), QVariant::fromValue<QString>(lineEdit->text()));
    if (!res)
    {
      qDebug() << QString("object->setProperty(%1, %2) return false").arg(mpro.name()).arg(lineEdit->text());
    }
    update();
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

  VPropertyItem* createItem(VPropertyItemParam param) override
  {
    if (param.mpro.userType() != userType) return nullptr;
    return new VPropertyItem_Base(param);
  }

protected:
  int userType;
};

#endif // __V_PROPERTY_WIDGET_ITEM_BASE_H__
