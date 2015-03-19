// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_ITEM_CREATOR_LINE_EDIT_H__
#define __V_PROPERTY_WIDGET_ITEM_CREATOR_LINE_EDIT_H__

#include <QDebug>
#include <QLineEdit>
#include "vpropertyitemcreator.h"

// ----------------------------------------------------------------------------
// VPropertyItemLineEdit
// ----------------------------------------------------------------------------
class VPropertyItemLineEdit : public QLineEdit
{
  Q_OBJECT

public:
  VPropertyItemLineEdit(QWidget* parent, QObject* object, QMetaProperty mpro) : QLineEdit(parent)
  {
    this->object = object;
    this->mpro = mpro;
    connect(this, SIGNAL(editingFinished()), this, SLOT(myEditingFinished()));
  }

public slots:
  void myEditingFinished()
  {
    object->setProperty(mpro.name(), QVariant::fromValue<QString>(this->text()));
    qDebug() << "VPropertyItemCreator_LineEdit::myEditingFinished" << mpro.name() <<  (void*)this; // gilgil temp 2015.03.17
  }

protected:
  QObject* object;
  QMetaProperty mpro;
};

// ----------------------------------------------------------------------------
// VPropertyItemCreatorLineEdit
// ----------------------------------------------------------------------------
class VPropertyItemCreatorLineEdit : public VPropertyItemCreator
{
public:
  VPropertyItemCreatorLineEdit(int userType)
  {
    this->userType = userType;
  }

  VPropertyItem* createItem(VPropertyEditor* editor, QObject* object, QMetaProperty mpro) override
  {
    if (mpro.userType() != userType) return nullptr;

    VPropertyItemLineEdit* lineEdit = new VPropertyItemLineEdit(editor, object, mpro);
    lineEdit->setFrame(false);
    QVariant value = object->property(mpro.name());
    lineEdit->setText(value.toString());

    VPropertyItem* item = new VPropertyItem(editor);
    item->setText(0, mpro.name());
    editor->setItemWidget(item, 1, lineEdit);
    return item;
  }

protected:
  int userType;
};

#endif // __V_PROPERTY_WIDGET_ITEM_CREATOR_LINE_EDIT_H__
