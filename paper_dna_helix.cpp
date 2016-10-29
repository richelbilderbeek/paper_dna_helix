#include "paper_dna_helix.h"

#include <cassert>

paper_dna_helix::paper_dna_helix(const int n_nucleotides)
  : m_n_nucleotides{n_nucleotides}
{
  assert(n_nucleotides > 0);
}


std::ostream& operator<<(std::ostream& os, const paper_dna_helix&) noexcept
{
  //Use A4 format
  os << "<svg width=\"210\" height=\"297\" stroke=\"black\" stroke-width=\"1\">\n";
  os << "  <line x1=\"50\" y1=\"50\" x2=\"200\" y2=\"200\" />\n";
  os << "  <line x1=\"50\" y1=\"50\" x2=\"50\" y2=\"200\" />\n";
  os << "  <line x1=\"50\" y1=\"150\" x2=\"200\" y2=\"300\" />\n";
  os << "</svg>";
  return os;
}
