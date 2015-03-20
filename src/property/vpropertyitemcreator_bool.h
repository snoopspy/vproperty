// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_ITEM_CREATOR_CHECK_BOX_H__
#define __V_PROPERTY_WIDGET_ITEM_CREATOR_CHECK_BOX_H__

#include <QCheckBox>
#include "vpropertyitemcreator.h"

// ----------------------------------------------------------------------------
// VPropertyItemCreator_Bool_CheckBox
// ----------------------------------------------------------------------------
class VPropertyItemCreator_Bool_CheckBox : public QCheckBox
{
  Q_OBJECT

public:
  VPropertyItemCreator_Bool_CheckBox(QWidget* parent, QObject* object, QMetaProperty mpro) : QCheckBox(parent)
  {
    this->object = object;
    this->mpro = mpro;

    connect(this, SIGNAL(clicked(bool)), this, SLOT(myClicked(bool)));
  }

public slots:
  void myClicked(bool checked)
  {
    object->setProperty(mpro.name(), checked);
  }

protected:
  QObject* object;
  QMetaProperty mpro;
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

    VPropertyItemCreator_Bool_CheckBox* checkBox = new VPropertyItemCreator_Bool_CheckBox(editor, object, mpro);
    QVariant value = object->property(mpro.name());
    checkBox->setChecked(value.toBool());

    VPropertyItem* item = new VPropertyItem(editor);
    item->setText(0, mpro.name());
    editor->setItemWidget(item, 1, checkBox);

    return item;
  }
};

#endif // __V_PROPERTY_WIDGET_ITEM_CREATOR_CHECK_BOX_H__
