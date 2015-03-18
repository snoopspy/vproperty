#include <QDebug> // gilgil temp
#include <QGridLayout>

#include "vpropertyeditor.h"
#include "vpropertywidgetfactory.h"

// ----------------------------------------------------------------------------
// VPropertyEditor
// ----------------------------------------------------------------------------
VPropertyEditor::VPropertyEditor(QWidget *parent) : QTreeWidget(parent)
{
  this->setColumnCount(2);
  QStringList sList; sList << "property" << "value";
  this->setHeaderLabels(sList);
  QLayout* layout = new QGridLayout(this);
  layout->setMargin(0);
  _object = nullptr;
}

VPropertyEditor::~VPropertyEditor()
{
}

QObject* VPropertyEditor::object()
{
  return _object;
}

void VPropertyEditor::setObject(QObject* object)
{
  if (object == _object) return;
  _object = object;
  VPropertyWidgetFactory& factory = VPropertyWidgetFactory::instance();

  const QMetaObject* mobj = object->metaObject();
  int propCount = mobj->propertyCount();
  for (int i = 0; i < propCount; i++)
  {
    QMetaProperty mpro = mobj->property(i);
    VPropertyWidget* widget = nullptr;
    VPropertyWidgetCreator* creatableObject = dynamic_cast<VPropertyWidgetCreator*>(object);
    if (creatableObject != nullptr)
    {
      widget = creatableObject->createWidget(this, object, mpro);
    }
    if (widget == nullptr)
    {
      widget = factory.createWidget(this, object, mpro);
    }
    if (widget == nullptr)
    {
      qDebug() << "item is nullptr" << mpro.name();
    }
    QTreeWidgetItem* widgetItem = new QTreeWidgetItem(this);
    widgetItem->setText(0, mpro.name());
    this->setItemWidget(widgetItem, 1, widget);
    //widgetItem->setBackground(1, QBrush(QColor(128, 128, 128))); // gilgil temp 2015.01.14
  }

  // gilgil temp 2015.03.17
}
