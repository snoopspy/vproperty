// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_H__
#define __V_PROPERTY_WIDGET_H__

#include <QWidget>

// ----------------------------------------------------------------------------
// VPropertyWidget
// ----------------------------------------------------------------------------
class VPropertyWidgetPrivate;
class VPropertyWidget : public QWidget
{
  Q_OBJECT
public:
  explicit VPropertyWidget(QWidget *parent = 0);
  virtual ~VPropertyWidget();

  void setObject(QObject* object);

private:
  VPropertyWidgetPrivate* d_ptr;
};

#endif // __V_PROPERTY_WIDGET_H__
