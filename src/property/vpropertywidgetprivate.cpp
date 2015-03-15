#include <QDebug> // gilgil temp 2015.03.16
#include <QLayout>
#include <QMetaProperty>
#include <QWidget>

#include "vpropertywidget.h"
#include "vpropertywidgetprivate.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetPrivate
// ----------------------------------------------------------------------------
VPropertyWidgetPrivate::VPropertyWidgetPrivate(QObject* parent) : QObject(parent)
{
  q_ptr = dynamic_cast<VPropertyWidget*>(parent);
  variantManager = new QtVariantPropertyManager(q_ptr);
  variantFactory = new QtVariantEditorFactory(q_ptr);
  browser = new QtTreePropertyBrowser(q_ptr);
  browser->setFactoryForManager(variantManager, variantFactory);
  Q_ASSERT(q_ptr->layout() != NULL);
  q_ptr->layout()->addWidget(browser);

  connect(variantManager, SIGNAL(valueChanged(QtProperty*,QVariant)), this, SLOT(valueChanged(QtProperty*,QVariant)));
}

VPropertyWidgetPrivate::~VPropertyWidgetPrivate()
{
}

QObject* VPropertyWidgetPrivate::object()
{
  return m_object;
}

void VPropertyWidgetPrivate::setObject(QObject* object)
{
  qDebug();
  if (m_object == object) return;
  m_object = object;
  const QMetaObject* metaObject = object->metaObject();
  addClassProperties(metaObject);
}

void VPropertyWidgetPrivate::addClassProperties(const QMetaObject *metaObject)
{
  if (metaObject == NULL) return;
  addClassProperties(metaObject->superClass());
  qDebug() << "class " << metaObject->className();
  int count = metaObject->propertyCount();
  for (int i = 0; i < count; i++)
  {
    QMetaProperty metaProperty = metaObject->property(i);
    qDebug() << "  " << metaProperty.typeName() << metaProperty.name();
    QtProperty *groupProperty = variantManager->addProperty(QtVariantPropertyManager::groupTypeId(), metaObject->className());
    browser->addProperty(groupProperty);
    //addProperty(gropuProperty, metaProperty);

    QtVariantProperty* stringProperty = variantManager->addProperty(QVariant::String, metaProperty.name());
    stringProperty->setValue(m_object->property(metaProperty.name()));
    groupProperty->addSubProperty(stringProperty);
  }
}


void VPropertyWidgetPrivate::valueChanged(QtProperty* property, const QVariant & value)
{
    //if (!m_propertyToIndex.contains(property))
    //    return;
  QObject* _object = object();
  const char* propertyName = qPrintable(property->propertyName());
  _object->setProperty(propertyName, value);
}
