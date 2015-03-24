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

struct VPropertyItemParam
{
  QTreeWidget* treeWidget;
  QObject* object;
  QMetaProperty mpro;
};

class VPropertyItem : public QObject, public QTreeWidgetItem
{
  Q_OBJECT
public:
  VPropertyItem(VPropertyItemParam param) : QTreeWidgetItem(param.treeWidget)
  {
    object = param.object;
    mpro = param.mpro;
    setText(0, mpro.name());
  }

  virtual void update() = 0;

protected:
  QObject* object;
  QMetaProperty mpro;
};

#endif // __V_PROPERTY_ITEM_H__
