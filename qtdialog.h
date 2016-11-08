#ifndef QTDIALOG_H
#define QTDIALOG_H

#include <QDialog>

namespace Ui {
  class QtDialog;
}

struct QSvgWidget;

class QtDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtDialog(QWidget *parent = 0);
  ~QtDialog();

private slots:
  void something_happened();
  void showEvent(QShowEvent *);

private:
  Ui::QtDialog *ui;
  QSvgWidget * const m_svg;
};

#endif // QTDIALOG_H
