// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PROPERTY_WIDGET_PRIVATE_H__
#define __V_PROPERTY_WIDGET_PRIVATE_H__

#include <QHash>
#include <QMetaProperty>
#include <QtVariantPropertyManager>
#include <QtVariantEditorFactory>
#include <QtTreePropertyBrowser>

class VPropertyWidget;
class VPropertyWidgetPrivate : public QObject
{
  Q_OBJECT

  friend class VPropertyWidget;

  VPropertyWidgetPrivate(QObject* parent);
  virtual ~VPropertyWidgetPrivate();

  QObject* object();
  void setObject(QObject* object);

  void addClassProperties(const QMetaObject *metaObject);

private:
  VPropertyWidget* q_ptr;
  QObject* m_object;
  QHash<QMetaProperty, QtProperty*> properties;

  QtVariantPropertyManager* variantManager;
  QtVariantEditorFactory *variantFactory;
  QtTreePropertyBrowser *browser;

private slots:
  void valueChanged(QtProperty* property, const QVariant & value);
};

uint qHash(const QMetaProperty metaProperty);

bool operator==(const QMetaProperty metaProperty1, const QMetaProperty metaProperty2);

#endif // __V_PROPERTY_WIDGET_PRIVATE_H__
