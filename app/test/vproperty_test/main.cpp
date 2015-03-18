#include <QApplication>
#include <VPropertyEditor>
#include "netclient.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  NetClient netClient;
  netClient.setObjectName("myNetClient");
  VPropertyEditor editor;
  editor.setObject(&netClient);
  editor.show();
  int res = a.exec();
  return res;
}
