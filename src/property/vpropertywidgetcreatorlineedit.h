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
#include "vpropertywidgetcreator.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetLineEdit
// ----------------------------------------------------------------------------
class VPropertyWidgetLineEdit : public QLineEdit
{
  Q_OBJECT

public:
  VPropertyWidgetLineEdit(QWidget* parent, QObject* object, QMetaProperty mpro) : QLineEdit(parent)
  {
    this->object = object;
    this->mpro = mpro;

    connect(this, SIGNAL(editingFinished()), this, SLOT(myEditingFinished()));
  }

public slots:
  void myEditingFinished()
  {
    object->setProperty(mpro.name(), QVariant::fromValue<QString>(this->text()));
    qDebug() << "VPropertyWidgetCreator_LineEdit::myEditingFinished" << mpro.name() <<  (void*)this; // gilgil temp 2015.03.17
  }

protected:
  QObject* object;
  QMetaProperty mpro;
};

// ----------------------------------------------------------------------------
// VPropertyWidgetCreatorLineEdit
// ----------------------------------------------------------------------------
class VPropertyWidgetCreatorLineEdit : public QObject, public VPropertyWidgetCreator
{
  Q_OBJECT

public:
  VPropertyWidgetCreatorLineEdit(int userType)
  {
    this->userType = userType;
  }

  VPropertyWidget* createPropertyWidgetItem(VPropertyEditor* editor,  QObject* object, QMetaProperty mpro) override
  {
    if (mpro.userType() != userType) return nullptr;
    VPropertyWidgetLineEdit* lineEdit = new VPropertyWidgetLineEdit(editor, object, mpro);
    lineEdit->setFrame(false);
    QVariant value = object->property(mpro.name());
    lineEdit->setText(value.toString());
    return lineEdit;
  }

protected:
  int userType;
};

#endif // __V_PROPERTY_WIDGET_ITEM_CREATOR_INT_H__
