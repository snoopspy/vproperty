#include <QGridLayout>

#include "vpropertywidget.h"
#include "vpropertywidgetprivate.h"

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
