#include <QApplication>
#include <QDebug>
#include <QFile>
#include <VPropertyWidget>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  qSetMessagePattern("%{type} %{threadid} (%{function} %{line}): %{message}");
  VPropertyWidget widget;
  QFile file;
  //widget.setGeometry(0, 0, 300, 500);
  file.setObjectName("temp");
  widget.setObject(&file);
  widget.show();
  int res = a.exec();
  qDebug() << file.objectName();
  return res;
}
