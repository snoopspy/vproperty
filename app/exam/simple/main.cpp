#include <QApplication>
#include <VPropertyWidget>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  VPropertyWidget widget;
  widget.setGeometry(0, 0, 300, 500);
  widget.show();
  return a.exec();
}
