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
  VPropertyWidget* createWidget(VPropertyEditor* editor, QObject* object, QMetaProperty mpro) override
  {
    if (mpro.userType() != QMetaType::Bool) return nullptr;
    VPropertyWidgetCheckBox* checkBox = new VPropertyWidgetCheckBox(editor, object, mpro);
    QVariant value = object->property(mpro.name());
    checkBox->setChecked(value.toBool());
    return checkBox;
  }
};

#endif // __V_PROPERTY_WIDGET_ITEM_CREATOR_CHECK_BOX_H__
