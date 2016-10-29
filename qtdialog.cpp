#include "qtdialog.h"
#include <cassert>
#include <fstream>
#include <sstream>
#include <QDebug>
#include <QtSvg>
#include "paper_dna_helix.h"
#include "ui_qtdialog.h"

QtDialog::QtDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::QtDialog),
  m_svg{new QSvgWidget(this)}
{
  ui->setupUi(this);
  assert(this->layout());
  this->layout()->addWidget(m_svg);
  //m_svg->setMinimumSize(QSize(200,200));

}

QtDialog::~QtDialog()
{
  delete ui;
}

void QtDialog::on_create_clicked()
{
  const std::string filename{"paper_dna_helix.svg"};
  {
    const paper_dna_helix h(14);
    std::ofstream f(filename);
    f << h;
    std::stringstream s;
    s << h;
    qDebug() << s.str().c_str();
  }
  assert(m_svg->isVisible());
  m_svg->load(QString(filename.c_str()));
}
