#include "vpropertyitemfactory.h"
#include "vpropertyitemcreatorcheckbox.h"
#include "vpropertyitemcreatorlineedit.h"

// ----------------------------------------------------------------------------
// VPropertyItemFactoryInstance
// ----------------------------------------------------------------------------
class VPropertyItemFactoryInstance : public VPropertyItemFactory
{
public:
  VPropertyItemFactoryInstance()
  {
    VPropertyItemCreatorLineEdit* intCreator = new VPropertyItemCreatorLineEdit(QMetaType::Int);
    this->append(intCreator);

    VPropertyItemCreatorLineEdit* stringCreator = new VPropertyItemCreatorLineEdit(QMetaType::QString);
    this->append(stringCreator);

    VPropertyItemCreatorCheckBox* boolCreator = new VPropertyItemCreatorCheckBox;
    this->append(boolCreator);
  }
  virtual ~VPropertyItemFactoryInstance()
  {
    // memory leak // gilgil temp 2105.03.18
  }
};

// ----------------------------------------------------------------------------
// VPropertyItemFactory
// ----------------------------------------------------------------------------
VPropertyItem* VPropertyItemFactory::createItem(VPropertyEditor* editor, QObject* object, QMetaProperty mpro)
{
  VPropertyItem* item = nullptr;
  for (QList<VPropertyItemCreator*>::iterator it = begin(); it != end(); it++)
  {
    VPropertyItemCreator* creator = *it;
    item = creator->createItem(editor, object, mpro);
    if (item != nullptr) break;
  }
  return item;
}

VPropertyItemFactory& VPropertyItemFactory::instance()
{
  static VPropertyItemFactoryInstance factory;
  return factory;
}
