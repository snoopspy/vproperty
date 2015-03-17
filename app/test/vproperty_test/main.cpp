#include <QApplication>
#include <VPropertyWidget>
#include "netclient.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  NetClient netClient;
  netClient.setObjectName("myNetClient");
  VPropertyWidget widget;
  widget.setObject(&netClient);
  widget.show();
  widget.show();
  int res = a.exec();
  return res;
}
