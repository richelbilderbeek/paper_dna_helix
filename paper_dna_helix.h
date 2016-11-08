#ifndef PAPER_DNA_HELIX_H
#define PAPER_DNA_HELIX_H

#include <iosfwd>
#include <vector>
#include "lines.h"

///Can be converted to SVG
class paper_dna_helix
{
public:
  paper_dna_helix(const int n_nucleotides);

private:
  ///The number of nucleotides
  const int m_n_nucleotides;
  const lines m_lines;


  lines create_dna_helix(const int n_nucleotides);
  lines create_nucleotide();

  friend std::ostream& operator<<(std::ostream& os, const paper_dna_helix& h) noexcept;
};

std::ostream& operator<<(std::ostream& os, const paper_dna_helix& h) noexcept;

#endif // PAPER_DNA_HELIX_H
