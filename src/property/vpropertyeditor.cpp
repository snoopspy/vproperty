#include <QDebug> // gilgil temp
#include <QGridLayout>

#include "vpropertyeditor.h"
#include "vpropertyitem_unknowntype.h"
#include "vpropertyitemfactory.h"

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
  VPropertyItemFactory& factory = VPropertyItemFactory::instance();

  const QMetaObject* mobj = object->metaObject();
  int propCount = mobj->propertyCount();
  for (int i = 0; i < propCount; i++)
  {
    QMetaProperty mpro = mobj->property(i);
    VPropertyItem* item = nullptr;
    VPropertyItemCreator* creatableObject = dynamic_cast<VPropertyItemCreator*>(object);
    VPropertyItemParam param {this, object, mpro};
    if (creatableObject != nullptr)
    {
      item = creatableObject->createItem(param);
    }
    if (item == nullptr)
    {
      item = factory.createItem(param);
    }
    if (item == nullptr)
    {
      qDebug() << "item is nullptr" << mpro.typeName() << mpro.name();
      new VPropertyItem_UnknownType(param);
    } else
    {
      item->update();
    }
  }
}
