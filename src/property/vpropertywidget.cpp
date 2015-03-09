#include <QDebug>
#include <QGridLayout>
#include <QMetaObject>
#include <QMetaProperty>
#include <QtTreePropertyBrowser>
#include <QtVariantPropertyManager>
#include "vpropertywidget.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetPrivate
// ----------------------------------------------------------------------------
class VPropertyWidgetPrivate
{
  friend class VPropertyWidget;

  VPropertyWidgetPrivate(QObject* parent)
  {
    q_ptr = dynamic_cast<VPropertyWidget*>(parent);
    variantManager = new QtVariantPropertyManager(q_ptr);
    browser = new QtTreePropertyBrowser(q_ptr);
    Q_ASSERT(q_ptr->layout() != NULL);
    q_ptr->layout()->addWidget(browser);
  }

  QObject* object() { return m_object; }
  void setObject(QObject* object)
  {
    qDebug();
    if (m_object == object) return;
    m_object = object;
    const QMetaObject* metaObject = object->metaObject();
    addClassProperties(metaObject);
  }

  void addClassProperties(const QMetaObject *metaObject)
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
    }
  }

protected:
  QObject* m_object;

protected:
  QtVariantPropertyManager* variantManager;
  QtTreePropertyBrowser *browser;

protected:
  VPropertyWidget* q_ptr;
};

// ----------------------------------------------------------------------------
// VPropertyWidget
// ----------------------------------------------------------------------------
VPropertyWidget::VPropertyWidget(QWidget* parent) : QWidget(parent)
{
  QLayout* layout = new QGridLayout(this);
  layout->setMargin(0);
  d_ptr = new VPropertyWidgetPrivate(this);
}

VPropertyWidget::~VPropertyWidget()
{
  delete d_ptr;
}

QObject* VPropertyWidget::object()
{
  return d_ptr->object();
}

void VPropertyWidget::setObject(QObject* object)
{
  d_ptr->setObject(object);
}

