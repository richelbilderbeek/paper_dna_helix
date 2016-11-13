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

  connect(ui->n_nucleotides, SIGNAL(valueChanged(int)), this, SLOT(something_happened()));
  connect(ui->nucleotide_width, SIGNAL(valueChanged(double)), this, SLOT(something_happened()));
  connect(ui->left_chain_angle, SIGNAL(valueChanged(int)), this, SLOT(something_happened()));
  connect(ui->backbone_margin, SIGNAL(valueChanged(int)), this, SLOT(something_happened()));
}

QtDialog::~QtDialog()
{
  delete ui;
}

void QtDialog::something_happened()
{
  const std::string filename{"paper_dna_helix.svg"};
  {
    const paper_dna_helix h(
      static_cast<double>(ui->left_chain_angle->value()) * 6.28 / 360.0,
      ui->n_nucleotides->value(),
      ui->nucleotide_width->value(),
      ui->backbone_margin->value()
    );
    std::stringstream s;
    s << h;
    qDebug() << s.str().c_str();
    std::ofstream f(filename);
    f << h;
  }
  m_svg->load(QString(filename.c_str()));
}

void QtDialog::showEvent(QShowEvent *)
{
  something_happened();
}
