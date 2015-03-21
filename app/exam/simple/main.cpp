#include <QApplication>
#include <QDebug>
#include <VPropertyEditor>

#include <QFile>
#include <QLabel>
#include <VTcpClient>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  qSetMessagePattern("%{type} %{threadid} (%{function} %{line}): %{message}");
  VPropertyEditor editor;
  //editor.setGeometry(0, 0, 300, 500);

  /*
  QFile file;
  file.setObjectName("temp");
  editor.setObject(&file);
  */

  /*
  QTcpServer tcpServer;
  tcpServer.setObjectName("myTcpServer");
  editor.setObject(&tcpServer);
  */

  /*
  QLabel label;
  label.setObjectName("myLabel");
  editor.setObject(&label);
  label.show();
  */

  VTcpClient tcpClient;
  tcpClient.setObjectName("myTcpClient");
  editor.setObject(&tcpClient);
  //tcpClient.show();

  editor.show();
  int res = a.exec();
  return res;
}
