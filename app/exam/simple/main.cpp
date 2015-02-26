#include <QApplication>
#include <QLineEdit>
#include <VPropertyWidget>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  qSetMessagePattern("%{type} %{threadid} %{file}(%{function} %{line}): %{message}");
  VPropertyWidget widget;
  QLineEdit lineEdit;
  //widget.setGeometry(0, 0, 300, 500);
  widget.setObject(&lineEdit);
  widget.show();
  return a.exec();
}

