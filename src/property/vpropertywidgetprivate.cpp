#include <QDebug> // gilgil temp 2015.03.16
#include <QLayout>
#include <QWidget>

#include "vpropertywidget.h"
#include "vpropertywidgetprivate.h"

uint qHash(const QMetaProperty metaProperty)
{
  return qHash(metaProperty.name());
}

bool operator==(const QMetaProperty metaProperty1, const QMetaProperty metaProperty2)
{
  return strcmp(metaProperty1.name(), metaProperty2.name()) == 0;
}

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
  properties.clear();
  const QMetaObject* metaObject = object->metaObject();
  addClassProperties(metaObject);
}

void VPropertyWidgetPrivate::addClassProperties(const QMetaObject *metaObject)
{
  if (metaObject == NULL) return;
  addClassProperties(metaObject->superClass());

  qDebug() << "class " << metaObject->className();
  QtProperty *groupProperty = variantManager->addProperty(QtVariantPropertyManager::groupTypeId(), metaObject->className());
  browser->addProperty(groupProperty);

  int count = metaObject->propertyCount();
  for (int i = 0; i < count; i++)
  {
    QMetaProperty metaProperty = metaObject->property(i);
    if (properties.find(metaProperty) != properties.end()) continue;
    qDebug() << "  " << metaProperty.typeName() << metaProperty.name();

    //addProperty(gropuProperty, metaProperty);

    QtVariantProperty* stringProperty = variantManager->addProperty(metaProperty.userType(), metaProperty.name());
    if (stringProperty == NULL)
    {
      qDebug() << "can not create property for" << metaProperty.name();
      continue;
    }
    stringProperty->setValue(m_object->property(metaProperty.name()));

    properties[metaProperty] = stringProperty;
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
