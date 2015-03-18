// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_EDITOR_H__
#define __V_PROPERTY_EDITOR_H__

#include <QTreeWidget>

// ----------------------------------------------------------------------------
// VPropertyEditor
// ----------------------------------------------------------------------------
class VPropertyEditor : public QTreeWidget
{
  Q_OBJECT
  Q_PROPERTY(QObject* object READ object WRITE setObject)

public:
  explicit VPropertyEditor(QWidget *parent = 0);
  virtual ~VPropertyEditor();

public:
  QObject* object();
  void setObject(QObject* object);

protected:
  QObject* _object;
};

#endif // __V_PROPERTY_EDITOR_H__
