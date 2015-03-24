// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_ITEM_H__
#define __V_PROPERTY_ITEM_H__

#include <QMetaProperty>
#include <QTreeWidgetItem>

class VPropertyItem : public QObject, public QTreeWidgetItem
{
  Q_OBJECT
public:
  VPropertyItem(QTreeWidget *view, QObject* object, QMetaProperty mpro) : QTreeWidgetItem(view)
  {
    this->object = object;
    this->mpro = mpro;
    this->setText(0, mpro.name());
  }

  virtual void update() = 0;

protected:
  QObject* object;
  QMetaProperty mpro;
};

#endif // __V_PROPERTY_ITEM_H__
