#include <QDebug> // gilgil temp
#include <QGridLayout>

#include "vpropertywidget.h"
#include "vpropertywidgetitemcreatormgr.h"

// ----------------------------------------------------------------------------
// VPropertyWidget
// ----------------------------------------------------------------------------
VPropertyWidget::VPropertyWidget(QWidget *parent) : QTreeWidget(parent)
{
  this->setColumnCount(2);
  QStringList sList; sList << "property" << "value";
  this->setHeaderLabels(sList);
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
  VPropertyWidgetItemCreatorMgr& mgr = VPropertyWidgetItemCreatorMgr::instance();

  const QMetaObject* mobj = object->metaObject();
  int propCount = mobj->propertyCount();
  for (int i = 0; i < propCount; i++)
  {
    QMetaProperty mpro = mobj->property(i);
    VPropertyWidgetItem* item = nullptr;
    for (QList<VPropertyWidgetItemCreator*>::iterator it = mgr.begin(); it != mgr.end(); it++)
    {
      VPropertyWidgetItemCreator* creator = *it;
      item = creator->createPropertyWidgetItem(this, object, mpro);
      if (item != nullptr) break;
    }
    if (item == nullptr)
    {
      qDebug() << "item is nullptr" << mpro.name();
      return;
    }
    this->insertTopLevelItem(i, item);
    item->setBackground(1, QBrush(QColor(128, 128, 128))); // gilgil temp 2015.01.14
  }

  // gilgil temp 2015.03.17
}
