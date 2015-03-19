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

#include <QDebug>
#include <QCheckBox>
#include "vpropertywidgetcreator.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetCheckBox
// ----------------------------------------------------------------------------
class VPropertyWidgetCheckBox : public QCheckBox
{
  Q_OBJECT

public:
  VPropertyWidgetCheckBox(QWidget* parent, QObject* object, QMetaProperty mpro) : QCheckBox(parent)
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
// VPropertyWidgetCreatorCheckBox
// ----------------------------------------------------------------------------
class VPropertyWidgetCreatorCheckBox : public VPropertyWidgetCreator
{
public:
  VPropertyWidgetCreatorCheckBox(int userType)
  {
    this->userType = userType;
  }

  VPropertyWidget* createWidget(VPropertyEditor* editor, QObject* object, QMetaProperty mpro) override
  {
    if (mpro.userType() != userType) return nullptr;
    VPropertyWidgetCheckBox* checkBox = new VPropertyWidgetCheckBox(editor, object, mpro);
    //checkBox->setFrame(false); // gilgil temp 2015.03.19
    QVariant value = object->property(mpro.name());
    checkBox->setChecked(value.toBool());
    return checkBox;
  }

protected:
  int userType;
};

#endif // __V_PROPERTY_WIDGET_ITEM_CREATOR_CHECK_BOX_H__
