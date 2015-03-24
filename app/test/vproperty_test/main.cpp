#include <QApplication>
#include <VPropertyEditor>

#include <QLineEdit>
#include "myobj.h"
#include "netclient.h"

QObject* createObject()
{
  //QObject* res = new NetClient;
  //QObject* res = new QLineEdit;
  QObject* res = new MyObj;

  res->setObjectName("myName");
  return res;
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  qSetMessagePattern("%{file}(%{line}): %{message}");
  QObject* object = createObject();
  VPropertyEditor editor;
  editor.setObject(object);
  editor.show();
  int res = a.exec();
  delete object;
  return res;
}
