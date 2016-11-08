#include "qtdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QtDialog w;
  w.showFullScreen();
  return a.exec();
}
