#include <QDebug>
#include <QGridLayout>
#include <QtTreePropertyBrowser>
#include "vpropertywidget.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetPrivate
// ----------------------------------------------------------------------------
class VPropertyWidgetPrivate
{
  friend class VPropertyWidget;

  VPropertyWidget* q_ptr;
  QtTreePropertyBrowser *browser;

  VPropertyWidgetPrivate(QObject* parent)
  {
    q_ptr = dynamic_cast<VPropertyWidget*>(parent);
    browser = new QtTreePropertyBrowser(q_ptr);
    Q_ASSERT(q_ptr->layout() != NULL);
    q_ptr->layout()->addWidget(browser);
  }
};

// ----------------------------------------------------------------------------
// VPropertyWidget
// ----------------------------------------------------------------------------
VPropertyWidget::VPropertyWidget(QWidget* parent) : QWidget(parent)
{
  QLayout* layout = new QGridLayout(this);
  layout->setMargin(0);
  m_object = NULL;
  d_ptr = new VPropertyWidgetPrivate(this);
}

VPropertyWidget::~VPropertyWidget()
{
  delete d_ptr;
}

void VPropertyWidget::setObject(QObject* object)
{
  qDebug();
  if (m_object == object) return;
}

