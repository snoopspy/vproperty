#include "vpropertywidgetfactory.h"
#include "vpropertywidgetcreatorcheckbox.h"
#include "vpropertywidgetcreatorlineedit.h"

// ----------------------------------------------------------------------------
// VPropertyWidgetFactoryInstance
// ----------------------------------------------------------------------------
class VPropertyWidgetFactoryInstance : public VPropertyWidgetFactory
{
public:
  VPropertyWidgetFactoryInstance()
  {
    VPropertyWidgetCreatorLineEdit* intCreator = new VPropertyWidgetCreatorLineEdit(QMetaType::Int);
    this->append(intCreator);

    VPropertyWidgetCreatorLineEdit* stringCreator = new VPropertyWidgetCreatorLineEdit(QMetaType::QString);
    this->append(stringCreator);

    VPropertyWidgetCreatorCheckBox* boolCreator = new VPropertyWidgetCreatorCheckBox(QMetaType::Bool);
    this->append(boolCreator);
  }
  virtual ~VPropertyWidgetFactoryInstance()
  {
    // memory leak // gilgil temp 2105.03.18
  }
};

// ----------------------------------------------------------------------------
// VPropertyWidgetFactory
// ----------------------------------------------------------------------------
VPropertyWidget* VPropertyWidgetFactory::createWidget(VPropertyEditor* editor, QObject* object, QMetaProperty mpro)
{
  VPropertyWidget* widget = nullptr;
  for (QList<VPropertyWidgetCreator*>::iterator it = begin(); it != end(); it++)
  {
    VPropertyWidgetCreator* creator = *it;
    widget = creator->createWidget(editor, object, mpro);
    if (widget != nullptr) break;
  }
  return widget;
}

VPropertyWidgetFactory& VPropertyWidgetFactory::instance()
{
  static VPropertyWidgetFactoryInstance factory;
  return factory;
}
