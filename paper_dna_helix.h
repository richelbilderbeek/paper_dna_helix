#ifndef PAPER_DNA_HELIX_H
#define PAPER_DNA_HELIX_H

#include <iostream>

///Can be converted to SVG
class paper_dna_helix
{
public:
  paper_dna_helix(const int n_nucleotides);

private:
  ///The number of nucleotides
  const int m_n_nucleotides;
};

std::ostream& operator<<(std::ostream& os, const paper_dna_helix& h) noexcept;

#endif // PAPER_DNA_HELIX_H
