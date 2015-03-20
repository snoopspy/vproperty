#include "vpropertyitemfactory.h"
#include "vpropertyitemcreator_base.h"
#include "vpropertyitemcreator_bool.h"

// ----------------------------------------------------------------------------
// VPropertyItemFactoryInstance
// ----------------------------------------------------------------------------
class VPropertyItemFactoryInstance : public VPropertyItemFactory
{
public:
  VPropertyItemFactoryInstance()
  {
    VPropertyItemCreator_Base* intCreator = new VPropertyItemCreator_Base(QMetaType::Int);
    this->append(intCreator);

    VPropertyItemCreator_Base* stringCreator = new VPropertyItemCreator_Base(QMetaType::QString);
    this->append(stringCreator);

    VPropertyItemCreator_Base* doubleCreator = new VPropertyItemCreator_Base(QMetaType::Double);
    this->append(doubleCreator);

    VPropertyItemCreator_Bool* boolCreator = new VPropertyItemCreator_Bool;
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
