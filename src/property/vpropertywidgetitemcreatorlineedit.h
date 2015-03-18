// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_ITEM_CREATOR_INT_H__
#define __V_PROPERTY_WIDGET_ITEM_CREATOR_INT_H__

#include <QDebug>
#include <QLineEdit>
#include "vpropertywidgetitemcreator.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetItemCreator_LineEdit
// ----------------------------------------------------------------------------
class VPropertyWidgetItemCreator_LineEdit : public QLineEdit
{
  Q_OBJECT

protected:
  QObject* object;
  QMetaProperty mpro;

public:
  VPropertyWidgetItemCreator_LineEdit(QWidget* parent, QObject* object, QMetaProperty mpro) : QLineEdit(parent)
  {
    this->object = object;
    this->mpro = mpro;
    connect(this, SIGNAL(editingFinished()), this, SLOT(myEditingFinished()));
  }
public slots:
  void myEditingFinished()
  {
    object->setProperty(mpro.name(), QVariant::fromValue<QString>(this->text()));
    qDebug() << "VPropertyWidgetItemCreator_LineEdit::myEditingFinished" << mpro.name() <<  (void*)this; // gilgil temp 2015.03.17
  }
};

// ----------------------------------------------------------------------------
// VPropertyWidgetItemCreatorLineEdit
// ----------------------------------------------------------------------------
template <int userType>
class VPropertyWidgetItemCreatorLineEdit : public VPropertyWidgetItemCreator
{
public:
  VPropertyWidgetItem* createPropertyWidgetItem(VPropertyWidget* widget,  QObject* object, QMetaProperty mpro) override
  {
    if (mpro.userType() != userType) return nullptr;
    VPropertyWidgetItem* item = new VPropertyWidgetItem;
    item->setText(0, mpro.name());
    VPropertyWidgetItemCreator_LineEdit * lineEdit = new VPropertyWidgetItemCreator_LineEdit(widget, object, mpro);
    widget->setItemWidget(item, 1, lineEdit);
    return item;
  }

protected:
  QLineEdit* lineEdit;
};

#endif // __V_PROPERTY_WIDGET_ITEM_CREATOR_INT_H__
