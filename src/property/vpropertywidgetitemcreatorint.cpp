#include <QDebug>
#include <QLineEdit>

#include "vpropertywidgetitemcreatorint.h"

class VPropertyWidgetItemCreatorIntLineEdit : public QLineEdit
{
public:
  VPropertyWidgetItemCreatorIntLineEdit(QWidget* parent) : QLineEdit(parent)
  {
    connect(this, SIGNAL(editingFinished()), this, SLOT(myEditingFinished()));
  }
public slots:
  void myEditingFinished()
  {
    qDebug() << "VPropertyWidgetItemCreatorIntLineEdit::myEditingFinished"; // gilgil temp 2015.03.17
  }
};

// ----------------------------------------------------------------------------
// VPropertyWidgetItemCreatorInt
// ----------------------------------------------------------------------------
VPropertyWidgetItem* VPropertyWidgetItemCreatorInt::createPropertyWidgetItem(QMetaProperty mpro)
{
  if (mpro.userType() != QMetaType::Int) return nullptr;
  VPropertyWidgetItem* item = new VPropertyWidgetItem;
}
