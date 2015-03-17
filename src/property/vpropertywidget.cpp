#include <QGridLayout>

#include "vpropertywidget.h"

// ----------------------------------------------------------------------------
// VPropertyWidget
// ----------------------------------------------------------------------------
VPropertyWidget::VPropertyWidget(QWidget *parent) : QTreeWidget(parent)
{
  QLayout* layout = new QGridLayout(this);
  layout->setMargin(0);
}

VPropertyWidget::~VPropertyWidget()
{

}

QObject* VPropertyWidget::object()
{
  return _object;
}

void VPropertyWidget::setObject(QObject* object)
{
  if (object == _object) return;
  _object = object;
  // gilgil temp 2015.03.17
}
