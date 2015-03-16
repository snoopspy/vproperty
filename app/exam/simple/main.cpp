#include <QApplication>
#include <QDebug>
#include <VPropertyWidget>

#include <QFile>
#include <QLabel>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  qSetMessagePattern("%{type} %{threadid} (%{function} %{line}): %{message}");
  VPropertyWidget widget;
  //widget.setGeometry(0, 0, 300, 500);

  /*
  QFile file;
  file.setObjectName("temp");
  widget.setObject(&file);
  */

  /*
  QTcpServer tcpServer;
  tcpServer.setObjectName("myTcpServer");
  widget.setObject(&tcpServer);
  */

  QLabel label;
  label.setObjectName("myLabel");
  widget.setObject(&label);
  label.show();

  widget.show();
  int res = a.exec();
  return res;
}
